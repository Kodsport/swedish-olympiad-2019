#include <bits/stdc++.h>
#include <random>
using namespace std;

namespace ng {
#include "accepted/ng.cpp"
#undef rep
#undef trav
#undef all
#undef sz
}
namespace ng2 {
#include "accepted/ng2.cpp"
#undef rep
#undef trav
#undef all
#undef sz
}
namespace fe {
#include "accepted/fe.cpp"
}

int main() {
	cin.sync_with_stdio(0);
	srand(0);
	int T; cin >> T;
	// fe is slightly better for T = 6, but takes too long
	if (T == 1 || T == 2 || T == 5 || T == 6 || T == 7 || T == 8) ng2::solve(T);
	else if (T == 10) fe::solve(T);
	else ng::solve(T);
}
