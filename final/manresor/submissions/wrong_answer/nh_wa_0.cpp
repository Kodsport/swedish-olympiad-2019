#include <bits/stdc++.h>
using namespace std;

struct ticket {
	int length;
	int price;
};

int N,M,K;
vector<int> DP;
set<int> visits;
vector<ticket> tickets;
set<int> sale;
const int inf = 1e9;
const int last_day = 1e5;

int calc(int day) {
	if (day > last_day) return 0;
	if (DP[day]!=-1) return DP[day];
	DP[day] = inf;
	auto it_next_visit = visits.upper_bound((day));
	int next_visit = inf;
	if (it_next_visit != visits.end()) next_visit = *it_next_visit;

	auto it_next_sale = sale.upper_bound((day));
	int next_sale = inf;
	if (it_next_sale != sale.end()) next_sale = *it_next_sale;

	int next_day = min(next_visit, next_sale);
	if (!visits.count(day)) {
		DP[day] = min(DP[day], calc(next_day)); 
	}
	for (const auto ticket : tickets) {
		int divisor = (sale.count(day)? 2:1);
		DP[day] = min(DP[day], ticket.price/divisor+calc(next_day));
		DP[day] = min(DP[day], ticket.price/divisor+calc(day+ticket.length));
	}
	return DP[day];
}


int main() {
	cin >> N >> M >> K;
	for (int i=0; i<N; ++i) {
		int day; cin >> day;
		visits.insert(day-1);
	}
	tickets.resize(M);
	for (int i=0; i<M; ++i) {
		cin >> tickets[i].length;
	}
	for (int i=0; i<M; ++i) {
		cin >> tickets[i].price;
	}
	for (int i=0; i<K; ++i) {
		int day; cin >> day;
		sale.insert(day-1);
	}
	DP.resize((int)1e5+1, -1);
	cout << calc(0) << endl;
}
