#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define sint(a) scanf("%d", &a)
#define MOD 1000000007

int n;

int main() {

	sint(n);

	ll ans1 = 1;
	ll ans2 = 1;
	for(int i = 2; i <= n; i++) {
		ans1 = (ans1 * i) % MOD;
		ans2 = (ans2 * 2) % MOD;
	}

	printf("%lld", (ans1 - ans2 + MOD) % MOD);

	return 0;
}