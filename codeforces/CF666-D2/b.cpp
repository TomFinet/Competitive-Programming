#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define mem(a, b) memset(a, b, sizeof(a))
#define MOD 1000000007
#define MAX (int) 1e9
#define PI 3.141592653589793238462643383279502884

const ll INF = 1e14;

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

inline ll absolute(ll a) { return a < 0 ? -1 * a : a; }

inline ll mul(ll a, ll b) { return INF / a > b ? a * b : INF; }

inline ll add(ll a, ll b) { return INF - a < b ? INF : a + b; }

int n;
ll a[100000];

int main() {

	cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);

	// we know that the maximum sum the sequence can have is
	// n * a_i = 10^9 * 10^5 = 10^14
	// therefore x^n-1 > 10^14, we can end our search and return the minimum
	// this is because it is sure that using 1 as a base is better than x

	ll res = INF;
	for(int x = 1; ; x++) {
		// compute the difference sum
		ll cost = 0, xpow = 1;
		for(int i = 0; i < n; i++) {
			cost = add(cost, absolute(a[i] - xpow));
			xpow = mul(xpow, x);
		}
		
		if(xpow > INF) {
			break;
		}

		res = min(res, cost);
	}
	
	cout << res << "\n";

	return 0;
}