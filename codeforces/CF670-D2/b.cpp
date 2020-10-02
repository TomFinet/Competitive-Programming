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

int t, n;
ll a[100005];

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> t;
	while(t--) {

		cin >> n;
		for(int i = 0; i < n; i++) cin >> a[i];

		sort(a, a + n);

		ll p1 = a[0] * a[1] * a[n - 1] * a[n - 2] * a[n - 3];
		ll p2 = a[0] * a[1] * a[2] * a[3] * a[n - 1];
		ll p3 = a[n - 1] * a[n - 2] * a[n - 3] * a[n - 4] * a[n - 5];

		cout << max(max(p1, p2), p3) << "\n";

	}

	return 0;
}