#include <bits/stdc++.h>
using namespace std;

void TestCase() {
	int n;
	string s;
	char ch;
	cin >> n >> s >> ch;
	vector<int> indices;
	for (int i = 0; i < n; i++) {
		if (s[i] == ch) {
			indices.push_back(i);
		}
	}
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		auto next = lower_bound(indices.begin(), indices.end(), i); // nearest index, where i <= index
		if (next == indices.end()) {
			continue;
		}
		ans += (n - *next); // total substrings for this i-th index
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc = 1;
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		TestCase();
	}
	return 0;
}

