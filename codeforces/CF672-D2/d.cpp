#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define mem(a, b) memset(a, b, sizeof(a))

const int MOD = 998244353;
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

int n, k, l, r;
ll fact[3005], invfact[3005];
ii p[300005];

ll expow(ll a, ll b) {
	ll res = 1;
	a %= MOD;
	while(b > 0) {
		if(b & 1) res = res * a % MOD;
		a = a * a % MOD; b >>= 1;
	}
	return res;
}

int choose(int a, int b) {
	if(a < b) return 0;
	return fact[a] * invfact[b] % MOD * invfact[a - b] % MOD;
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> k;

	fact[0] = 1;
	for(ll i = 1; i <= k; i++) fact[i] = (fact[i - 1] * i) % MOD;

	invfact[k] = expow(fact[k], MOD - 2) % MOD;
	for(int i = k - 1; i >= 0; i--) {
		invfact[i] = (i + 1) * invfact[i + 1];
		cout << invfact[i] << "\n";
	}

	for(int i = 0; i < n; i++) {
		cin >> l >> r;
		p[i] = make_pair(l, r);
	}

	sort(p, p + n);
	// all segments are sorted according to their leftmost end.

	int fixR = p[0].second;
	ll ans = 0;
	ll ways = 1;
	for(int i = 1; i < n; i++) {
		if(p[i].first <= fixR) {
			ways++;
		} else {
			ans += choose(ways, k) % MOD;
			ways = 0;
		}
		fixR = min(fixR, p[i].second);
	}

	ans += choose(ways, k) % MOD;
	ans = (ans + MOD) % MOD;
	
	cout << ans  << "\n";

	return 0;
}