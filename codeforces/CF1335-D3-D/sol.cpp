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

int n;

int main() {
	
	sint(n);
	int a[n], b[n], c[n];

	for(int i = 0; i < n; i++) { sint(a[i]); }
	for(int i = 0; i < n; i++) { sint(b[i]); }
	for(int i = 0; i < n; i++) { c[i] = a[i] - b[i]; }

	sort(c, c + n);
 
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		int pos = lower_bound(c, c + n, 1 - c[i]) - c;
		ans += n - max(pos, i + 1);
	}

	printf("%lld\n", ans);

	return 0;
}