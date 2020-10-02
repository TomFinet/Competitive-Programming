#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int MOD = 1000000007;
const double PI = 3.141592653589793238462643383279502884;
const int INF = 2000005;

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

// dp[i][player whose turn it is to kill ith boss] = minimum skip points used to kill ith boss
// dp[0] = a[0]
// on the i^th boss either you or your friend can kill the boss
// so if its a 0 we use the friend and if 1 we use you.
// dp[1] = dp[0]
// from dp[i >= 2] either your friend killed last two or you did

const int f = 0;
const int y = 1;

// dp[i][j][k] = min skips to beat (i + 1)^th boss, on j's turn with (k + 1) turns left 
int dp[200005][2][2];
int t, n, a[200005];

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> t;
	while(t--) {

		cin >> n;
		for(int i = 0; i < n; i++) {
			dp[i][f][1] = INF;
			dp[i][f][0] = INF;
			dp[i][y][1] = INF;
			dp[i][y][0] = INF;
		}

		for(int i = 0; i < n; i++) cin >> a[i];

		dp[0][f][1] = a[0];
		for(int i = 1; i < n; i++) {
			// at the ith boss we can have one of two players playing
			// with 1 or 2 turns left. 2 * 2 = 4 possibilities
			dp[i][f][1] = min(dp[i - 1][y][1], dp[i - 1][y][0]) + a[i];
			dp[i][f][0] = dp[i - 1][f][1] + a[i];
			dp[i][y][1] = min(dp[i - 1][f][1], dp[i - 1][f][0]);
			dp[i][y][0] = dp[i - 1][y][1];
		}

		int ans = min(dp[n - 1][f][1], dp[n - 1][f][0]);
		ans = min(ans, dp[n - 1][y][1]);
		ans = min(ans, dp[n - 1][y][0]);

		cout << ans << "\n";
	}

	return 0;
}
