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

int t, n, a[3005];

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> t;
	while(t--) {

		cin >> n;
		for(int i = 0; i < n; i++) cin >> a[i];

		ll ans = 0;
		int seenLeft[3005] = {0};
		for(int j = 0; j < n; j++) {
			int seenRight[3005] = {0};
			for(int k = n - 1; k > j; k--) {
				ans += seenRight[a[j]] * seenLeft[a[k]];
				seenRight[a[k]]++;
			}
			seenLeft[a[j]]++;
		}

		cout << ans << "\n";
	}

	return 0;
}