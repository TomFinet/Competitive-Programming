#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define mem(a, b) memset(a, b, sizeof(a))

const int MOD = 1000000007;
const double PI = 3.141592653589793238462643383279502884;
const ll INF = 1e18;

template <typename T, typename U>
T max(T x, U y) {
    return x > y ? x : y;
}

template <typename T, typename U>
T min(T x, U y) {
    return x < y ? x : y;
}

template<typename T>
void debug(string msg, T t) {
	cout << msg << ": " << t << "\n";
}

inline int toDigit(char c) { return c - '0'; }

int t, n, cntR, cntL, ans;
string s;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> t;
	while(t--) {

		cin >> n >> s;
		
		int offset = 0;

		for(; offset < n; offset++) {
			int j = offset - 1;
			if(offset == 0) j = n - 1;
			if(s[offset] != s[j]) break;
		}

		if(offset == n) { cout << (n + 2) / 3 << "\n"; }
		else {

			ans = 0;
			cntR = 0, cntL = 0;
			for(int i = offset; i < offset + n; i++) {
				if(s[i % n] == 'L') {
					ans += cntR / 3;
					cntR = 0; cntL++;
				} else {
					ans += cntL / 3;
					cntL = 0; cntR++;
				}
			}

			ans += cntL / 3;
			ans += cntR / 3;

			cout << ans << "\n";
		}

	}

	return 0;
}
