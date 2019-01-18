// usage: ./a.out input_file < contestants_output

#include <bits/stdc++.h>
using namespace std;

struct Point { int64_t x, y; };

int main(int argc, char** argv) {
	if (argc < 2) {
		cout << "not enough arguments" << endl;
		return 1;
	}
	
	Point p[3];
	int64_t n, m;
	
	ifstream inDataStream(argv[1]);
	inDataStream >> n >> m >> p[0].x >> p[0].y >> p[1].x >> p[1].y;
	
	cin >> p[2].x >> p[2].y;
	
	if (!cin) {
		cout << "io error" << endl;
		return 43;
	}
	
	if (p[2].x < 0 || p[2].x >= n || p[2].y < 0 || p[2].y >= m) {
		cout << "WA: out of range" << endl;
		return 43;
	}
	
	bool anyAngleBig = false;
	for (int i = 0; i < 3; i++) {
		int64_t dx1 = p[(i + 1) % 3].x - p[i].x;
		int64_t dy1 = p[(i + 1) % 3].y - p[i].y;
		int64_t dx2 = p[(i + 2) % 3].x - p[i].x;
		int64_t dy2 = p[(i + 2) % 3].y - p[i].y;
		
		int64_t dot = dx1 * dx2 + dy1 * dy2;
		int64_t cross = dx1 * dy2 - dy1 * dx2;
		
		if (cross == 0) {
			cout << "WA: degenerate" << endl;
			return 43;
		}
		
		if (dot < 0) {
			anyAngleBig = true;
		}
	}
	
	if (!anyAngleBig) {
		cout << "WA: not obtuse" << endl;
		return 43;
	}
	
	return 42;
}
