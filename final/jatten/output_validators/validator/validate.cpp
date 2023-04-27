// usage: ./a.out input_file < contestants_output

#include "validate.h"

#include <bits/stdc++.h>
using namespace std;

struct Point { int64_t x, y; };

int main(int argc, char** argv) {
	init_io(argc, argv);

	Point p[3];
	int64_t n, m;
	
	judge_in >> n >> m >> p[0].x >> p[0].y >> p[1].x >> p[1].y;
	
	
	auto check = [&](istream& sol, feedback_function feedback){
		if(!(sol >> p[2].x)) feedback("Expected more output");
		if(!(sol >> p[2].y)) feedback("Expected more output");

		if (p[2].x < 0 || p[2].x >= n || p[2].y < 0 || p[2].y >= m) {
			feedback("Output out of range");
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
				feedback("Degenerate triangle");
			}
			
			if (dot < 0) {
				anyAngleBig = true;
			}
		}
		
		if (!anyAngleBig) {
			feedback("Not obtuse");
		}

		string trailing;
		if(sol >> trailing) feedback("Trailing output");
		return true;
	};

	bool judge_found_sol = check(judge_ans, judge_error);
	bool author_found_sol = check(author_out, wrong_answer);

	if(!judge_found_sol)
		judge_error("Judge didn't find solution");

	if(!author_found_sol)
		wrong_answer("Contestant didn't find solution");

	accept();
}
