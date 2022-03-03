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
			indices.push_back(i); // store the indices where the character can be found
		}
	}
	if (indices.empty()) { // output 0 if there are no occurrences of the character
		cout << "0\n";
		return;
	}
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		// find the lowest index where the current i-th index is greater than (nearest largest idnex)
		if (i <= indices.back()) { 
			int low = 0;
			int high = (int) indices.size() - 1;
			int mx = INT_MIN;
			while (low <= high) { // perform binary search
				int mid = low + (high - low) / 2;
				if (i <= indices[mid]) {
					// no. of substrings that are valid = last index - nearest index to the 
					// current index (where the character is found)
					mx = max(mx, n - indices[mid]);
					high = mid - 1;
				} else {
					low = mid + 1;
				}
			}
			if (mx != INT_MIN) { // add the no. of substrings
				ans += mx;
			}
		} else {
			break;
		}
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

