#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define sint(a) scanf("%d", &a)
#define slong(a) scanf("%lld", &a);
#define mem(a, b) memset(a, b, sizeof(a))
#define iter(it, l) for(auto it = l.begin(); it != l.end(); it++)
//#define MOD 1000000007
#define MAX (int) 1e9
#define PI 3.141592653589793238462643383279502884

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

int toDigit(char c) { return c - '0'; }

const int MOD = 10000007;

int t;
ll n, k;

ll expo(ll a, ll b) {
	ll res = 1;
	while(b > 0) {
		if(b & 1) {
			res = (res * a) % MOD;
		}
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}

int main() {

	while(1) {
		scanf("%lld %lld", &n, &k);

		if(n == 0 && k == 0) {
			break;
		}

		ll a = expo(n - 1, k);
		ll b = expo(n, k);
		ll c = expo(n - 1, n - 1);
		ll d = expo(n, n);

		printf("%lld\n", (2 * a + b + 2 * c + d) % MOD);
	}
	
	return 0;
}