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

const int MAXPOW = 17;

int t, n, maxC, dp[150000][MAXPOW], freq[150000][26];
string s;

int cost(int i, int p) {
	int c = maxC - (p + 1);
	cout << "p: " << p << "\n";
	cout << "c: " << c << "\n";
	return (1 << p) - (freq[i + (1 << p)][c] - freq[i - 1][c]);
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> t;
	while(t--) {

		memset(dp, 0, sizeof(dp));
		memset(freq, 0, sizeof(freq));

		cin >> n >> s;

		maxC = 0;
		for(; (1 << maxC) < n; maxC++);

		for(int i = 1; i < n; i++) {
			for(int j = 0; j < 26; j++) {
				freq[i][j] = freq[i - 1][j];
			}
			freq[i][s[i] - 'a']++;
		}

		for(int i = 0; i < n; i++) dp[i][0] = s[i] != ('a' + maxC);

		for(int j = 1; j <= maxC; j++) {
			for(int i = 0; i <= n - (1 << j); i++) {
				dp[i][j] = min(dp[i][j - 1] + cost(i + (1 << (j - 1)), j - 1), 
							   dp[i + (1 << (j - 1))][j - 1] + cost(i, j - 1));
				}
		}

		cout << dp[0][maxC] << "\n";

	}

	return 0;
}