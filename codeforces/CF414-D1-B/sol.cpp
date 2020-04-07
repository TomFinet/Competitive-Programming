// Good look Mashmokh, all the best with the math competitions. You have a bright future ahead.
 
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
 
#define MOD 1000000007
 
int n, k, s;
ll out = 0; 
 
int main() {
 
	scanf("%d %d", &n, &k);
	ll goods[k][n];
	memset(goods, 0, sizeof(goods));
 
	for(int j = 0; j < n; j++) {
		goods[0][j] = 1;
	}
 
	for(int i = 1; i < k; i++) { // length
		for(int j = 0; j < n; j++) { // last element in sequence of size i
			s = 0;
			for(int k = 1; k * k <= (j + 1); k++) {
				if((j + 1) % k == 0) {
					int tmp = ((j + 1) / k);
					if(tmp != k) {
						s = (s + goods[i - 1][k - 1] + goods[i - 1][tmp - 1]) % MOD;
					} else {
						s = (s + goods[i - 1][k - 1]) % MOD;
					}
					
				}
			}
			goods[i][j] = s;
		}
	}
 
	for(int i = 0; i < n; i++) {
		out = (out + goods[k - 1][i]) % MOD;
	}
 
	printf("%llu\n", out);
 
	return 0;
}