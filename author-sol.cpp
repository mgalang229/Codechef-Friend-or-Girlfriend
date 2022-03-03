#include <bits/stdc++.h>
using namespace std;

void TestCase() {
	int n;
	string s;
	char ch;
	cin >> n >> s >> ch;
	vector<int> p = {-1};
	for (int i = 0; i < n; i++) {
		if (s[i] == ch) {
			p.push_back(i); // indices where the character is found
		}
	}
	p.push_back(n);
	int ans = n * (n + 1) / 2; // total no. of substrings of the whole string
	for (int i = 1; i < (int) p.size(); i++) {
		int len = p[i] - p[i-1] - 1; // length of the substring where the character is not found
		// len * (len + 1) / 2 = total no. of substrings of the substring where the character is not found
		ans -= len * (len + 1) / 2; // subtract the calculated value from the total no. of substrings
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

