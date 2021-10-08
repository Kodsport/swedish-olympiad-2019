#include <bits/stdc++.h>
using namespace std;

struct Node {
	int x;
	int y;
	int bestAfter;
	int newBestAfter;
};

struct Edge {
	int n1;
	int n2;
	int64_t dist;
};

int main() {
	int N;
	cin >> N;
	
	vector<Node> nodes(N);
	for (int i = 0; i < N; i++) {
		cin >> nodes[i].x >> nodes[i].y;
		nodes[i].bestAfter = 0;
		nodes[i].newBestAfter = -1;
	}
	
	vector<Edge> edges;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			int64_t dx = nodes[i].x - nodes[j].x;
			int64_t dy = nodes[i].y - nodes[j].y;
			edges.push_back({ i, j, dx * dx + dy * dy });
		}
	}
	
	sort(edges.begin(), edges.end(), [] (const Edge& a, const Edge& b) { return a.dist < b.dist; });
	
	vector<int> changed;
	int64_t prevDist = edges.back().dist;
	
	int ans = 0;
	for (int i = edges.size() - 1; i >= 0; i--) {
		if (prevDist != edges[i].dist) {
			for (int c : changed) {
				nodes[c].bestAfter = max(nodes[c].bestAfter, nodes[c].newBestAfter);
				nodes[c].newBestAfter = -1;
			}
			prevDist = edges[i].dist;
			changed.clear();
		}
		
		int v1 = nodes[edges[i].n2].bestAfter + 1;
		int v2 = nodes[edges[i].n1].bestAfter + 1;
		ans = max(ans, max(v1, v2));
		
		if (nodes[edges[i].n1].newBestAfter == -1)
			changed.push_back(edges[i].n1);
		if (nodes[edges[i].n2].newBestAfter == -1)
			changed.push_back(edges[i].n2);
		
		nodes[edges[i].n1].newBestAfter = max(nodes[edges[i].n1].newBestAfter, v1);
		nodes[edges[i].n2].newBestAfter = max(nodes[edges[i].n2].newBestAfter, v2);
	}
	
	cout << (ans + 1) << endl;
}
