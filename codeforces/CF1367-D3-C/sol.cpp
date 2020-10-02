#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

template <typename T, typename U>
T max(T x, U y) {
    return x > y ? x : y;
}

template <typename T, typename U>
T min(T x, U y) {
    return x < y ? x : y;
}

int t, n, k, ans;
string s;

inline int pack(int empty) {
	return (empty + k) / (k + 1);
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> t;
	while(t--) {

		cin >> n >> k >> s;

		ans = 0;
		for(int i = 0; i < n; i++) {

			int j = i + 1;

			for(; s[j] == 0 && j < n; j++);

			int len = j - i;

			// calculate length of useable zeros.
			if(s[i] == '1') {
				len -= k;
			} else {
				len++;
			}

			if(s[j] == '1') {
				len -= (1 + k);
			}

			if(len > 0) {
				ans += pack(len);
			}

			i = j;

		}

		cout << ans << "\n";
	}

	return 0;
}