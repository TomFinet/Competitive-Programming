#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define MOD 1000000007

int n, k;
ll count = 1; 

int main() {

	scanf("%d %d", &n, &k);

	for(int i = 1; i <= n; i++) {
		int maxMultiplier = n / i;
		int m = 1;
		while(m <= maxMultiplier) {
			count *= m % MOD;
		}
	}

	return 0;
}