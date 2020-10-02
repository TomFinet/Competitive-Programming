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

const int even = 0;
const int odd = 1;

int t, n, q, a[300005], l , r;
ll dp[300005][2];

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> t;
	while(t--) {

		cin >> n >> q;
		for(int i = 0; i < n; i++) {
			cin >> a[i]; 
			dp[i][even] = dp[i][odd] = 0;
		}

		// for each a[i] decide wether or not to include it in the sum
		dp[0][odd] = a[0];
		for(int i = 1; i < n; i++) {
			dp[i][odd] = max(dp[i - 1][odd], dp[i - 1][even] + a[i]);
			dp[i][even] = max(dp[i - 1][even], dp[i - 1][odd] - a[i]);
		}		

		cout << dp[n - 1][odd] << "\n";

	}

	return 0;
}