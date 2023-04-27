// usage: ./a.out input_file correct_output output_dir < contestants_output
#pragma GCC optimize ("O3")

#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> pii;

static string input_file, output_dir, answer_file;

void die(const string& msg) {
    cout << msg << endl;
    ofstream(output_dir + "/score.txt") << 0;
    exit(43);
}

void accept(double score) {
    ofstream(output_dir + "/score.txt") << setprecision(2) << fixed << score;
    exit(42);
}

void judge_error(const string& msg) {
	cout << msg << endl;
	exit(1);
}

template <class F>
void assert_done(istream& is, F fail) {
    try {
        string dummy;
        is >> dummy;
		if (is) fail("extraneous data: " + dummy);
    } catch(...) {}
}

template <class F>
ll score(istream& is, vector<vi>& grid, int K, F fail) {
	int N = sz(grid);
	int M = sz(grid[0]);
	vector<pii> positions(K);
	rep(i,0,K) {
		int r, c;
		is >> r >> c;
		if (!is) fail("EOF");
		if (!(1 <= r && r <= N)) fail("Row out of bounds");
		if (!(1 <= c && c <= M)) fail("Column out of bounds");
		r--;
		c--;
		positions[i] = pii(r, c);
	}
	assert_done(is, fail);

	assert(N <= 10000);
	assert(M <= 10000);
	sort(all(positions));
	vector<short> xs(K), ys(K);
	rep(i,0,K) {
		xs[i] = (short)positions[i].first;
		ys[i] = (short)positions[i].second;
	}

	// SIMD this for simplicity... max K is 40'000 or so, and we can use short's
	ll sum = 0;
	rep(i,0,K) {
		short x = xs[i];
		short y = ys[i];
		short mindist = SHRT_MAX;
		rep(j,0,i) {
			short dx = (short)(x - xs[j]); // sorted by x, so we don't need abs here
			short dy = (short)(y - ys[j]);
			dy = (dy < 0 ? (short)-dy : dy);
			short d = (short)(dx + dy);
			mindist = min((short)mindist, d);
		}
		rep(j,i+1,K) {
			short dx = (short)(xs[j] - x);
			short dy = (short)(ys[j] - y);
			dy = (dy < 0 ? (short)-dy : dy);
			short d = (short)(dx + dy);
			mindist = min((short)mindist, d);
		}
		if (mindist == 0) fail("Multiple houses at the same position");
		sum += (ll)mindist * grid[x][y];
	}
	return sum;
}

int main(int argc, char** argv) {
    if (argc < 4) exit(1);
    cin.sync_with_stdio(0);
    cin.tie(0);

    input_file = argv[1];
    answer_file = argv[2];
    output_dir = argv[3];

    ifstream fin(input_file);
    fin.exceptions(cin.failbit | cin.badbit | cin.eofbit);

    int T;
    fin >> T;

    int N, M, K;
    fin >> N >> M >> K;

	vector<vi> grid(N, vi(M));
	rep(i,0,N) rep(j,0,M) fin >> grid[i][j];

    assert_done(fin, die);
    fin.close();

	ifstream fans(answer_file);

    try {
		ll sc = score(cin, grid, K, die);
		ll bestsc = score(fans, grid, K, judge_error);
		double ratio = (double)sc / (double)bestsc;
                ratio = min(1.0, ratio*ratio);
		if (T == 0) accept(0);
		else accept(10.0 * ratio * ratio);
    } catch(...) {
        die("IO failure");
    }
}
