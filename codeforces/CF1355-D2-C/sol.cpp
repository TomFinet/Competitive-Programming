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

ll sum(ll a, ll d, ll n) {
	return (2 * a + n * d) * n / 2;
}

int a, b, c, d;
ll ans;

int main() {
	
	scanf("%d %d %d %d", &a, &b, &c, &d);

	// determine all possible x+y and their frequencies
	ll xPlusY[b + c + 1] = {0};
	for(int x = a; x <= b; x++) {
		xPlusY[x + b]++;
		xPlusY[x + c + 1]--; 
	}

	// getting frequencies using prefix sums
	for(int i = b + a; i <= b + c; i++) {
		xPlusY[i] += xPlusY[i - 1];
	}

	// count number of x + y >= xPlusY[i]
	for(int i = c + b - 1; i >= 0; i--) {
		xPlusY[i] += xPlusY[i + 1];
	}

	for(int z = c; z <= d; z++) {
		if(z + 1 > b + c) {
			continue;
		}

		ans += xPlusY[z + 1];
	}

	printf("%lld\n", ans);

	return 0;
}