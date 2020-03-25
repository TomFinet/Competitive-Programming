#include <bits/stdc++.h>

using namespace std;

int main() {

	int t, n, k, p;
	scanf("%d", &t);

	for(int ti = 1; ti <= t; ti++) {
		scanf("%d %d %d", &n, &k, &p);
		int s[n][k];

		for(int i = 0; i < n; i++) {
			for(int j = 0; j < k; j++) { 
				scanf("%d", &s[i][j]);
			}
		}

		int sum[n + 1][k + 1];
		memset(sum, 0, sizeof(sum));
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= k; j++) {
				sum[i][j] = sum[i][j - 1] 
					+ s[i - 1][j - 1];
			}
		}
		
		int maxS[n + 1][p + 1];
		memset(maxS, 0, sizeof(maxS));
		for(int i = 1; i <= n; i++) {
			for(int j = 0; j <= p; j++) {
				for(int l = 0; l <= min(j, k); l++) {
					maxS[i][j] = max(
						maxS[i - 1][j - l] + sum[i][l],
						maxS[i][j]
					);
				}
			}
		}

		printf("Case #%d: %d\n", ti, maxS[n][p]);
	}

	return 0;
}