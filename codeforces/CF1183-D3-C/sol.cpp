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
#define MOD 1000000007
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

ll t, k, n, a, b;

int main() {

	sint(t);
	while(t--) {
		scanf("%lld %lld %lld %lld", &k, &n, &a, &b);

		ll tmpK = k;
		int l = 0, r = min((int) ceil((k / (double)a) - 1.0), n), m, maxM = -1;
		while(l <= r) {
			m = l + (r - l) / 2;
			k = k - (m * a + (n - m) * b);
			
			if(k > 0) {
				maxM = max(maxM, m);
				l = m + 1;
			} else {
				r = m - 1;
			}

			k = tmpK;
		}

		printf("%d\n", maxM);
	}
	
	return 0;
}