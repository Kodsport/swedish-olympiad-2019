#include <bits/stdc++.h>
using namespace std;

struct Point { long x, y; };

Point p[3];
long n, m;

void check(long x, long y) {
	if (x < 0 || y < 0 || x >= n || y >= m)
		return;
	
	p[2].x = x;
	p[2].y = y;
	
	bool anyAngleBig = false;
	for (int i = 0; i < 3; i++) {
		long dx1 = p[(i + 1) % 3].x - p[i].x;
		long dy1 = p[(i + 1) % 3].y - p[i].y;
		long dx2 = p[(i + 2) % 3].x - p[i].x;
		long dy2 = p[(i + 2) % 3].y - p[i].y;
		
		long dot = dx1 * dx2 + dy1 * dy2;
		long maxD2 = (dx1 * dx1 + dy1 * dy1) * (dx2 * dx2 + dy2 * dy2);
		
		if (dot < 0) {
			if (dot * dot == maxD2)
				return;
			anyAngleBig = true;
		}
	}
	
	if (!anyAngleBig)
		return;
	
	cout << x << " " << y << endl;
	exit(0);
}

int main() {
	cin >> n >> m >> p[0].x >> p[0].y >> p[1].x >> p[1].y;
	
	const long M = 3;
	for (long dx = -M; dx <= M; dx++) {
		for (long dy = -M; dy <= M; dy++) {
			check(p[0].x + dx, p[0].y + dy);
			check(p[1].x + dx, p[1].y + dy);
		}
	}
	
	cout << "impossible" << endl;
}
