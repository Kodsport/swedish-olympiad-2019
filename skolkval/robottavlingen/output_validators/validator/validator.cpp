#include "validator.h"

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define debug(...) // ignore
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

int main(int argc, char **argv) {
  init_io(argc, argv);

  auto check = [&](istream &sol, feedback_function feedback) -> pair<int, int> {
    int sol_lo, sol_hi;

    if (!(sol >> sol_lo >> sol_hi))
      feedback("Expected more output");
    if (sol_lo > sol_hi)
      feedback("Upperbound can't be below");

    string trailing;
    if (sol >> trailing)
      feedback("Trailing output");
	return {sol_lo, sol_hi};
  };
  auto [judge_lo, judge_hi] = check(judge_ans, judge_error);
  auto [author_lo, author_hi] = check(author_out, wrong_answer);

  if (argc >= 5 && strcmp(argv[4], "maxOnly=yes") == 0) {
    if (judge_hi != author_hi) {
      wrong_answer("Upperbounds did not match");
    } else {
      accept();
    }
  }
  if (judge_lo == author_lo && judge_hi == author_hi) {
    accept();
  } else {
    wrong_answer("Output did not match judge");
  }
}
