#include <bits/stdc++.h>
using namespace std;

int main() {
	int N; cin >> N;
	unordered_map<string,pair<string,int>> birthdays_to_person;
	for (int i=0; i<N; ++i) {
		string name, birthday; 
		int like;
		cin >> name >> like >> birthday;
		if (!birthdays_to_person.count(birthday)) birthdays_to_person[birthday] = make_pair(name,like);
		if (like > birthdays_to_person[birthday].second) {
			birthdays_to_person[birthday] = make_pair(name,like);
		}
	}
	vector<string> remaining_friends;
	for (const auto &date_name_like : birthdays_to_person) {
		remaining_friends.push_back(date_name_like.second.first);
	}
	sort(remaining_friends.begin(), remaining_friends.end());
	cout << remaining_friends.size() << endl;
	for (int i=0; i<remaining_friends.size(); ++i) {
		cout << remaining_friends[i] << endl;
	}
}