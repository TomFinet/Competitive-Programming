#include <bits/stdc++.h>

using namespace std;

int main() {

	int t, n;
	scanf("%d", &t);

	for(int i = 1; i <= t; i++) {
		scanf("%d", &n);
		int a[n];
		for(int j = 0; j < n; j++) {
			scanf("%d", &a[j]);
		}

		int b[2*n];
		for(int j = 0; j < 2 * n; j++) {
			b[j] = a[j % n];
		}

		int sub = 1, maxSub;
		for(int j = 1; j < 2 * n; j++) {
			if(b[j] > b[j - 1]) {
				sub++;
			} else {
				maxSub = max(maxSub, sub);
				if(j >= n) {
					break;
				}
				sub = 1;
			}
		}

		printf("%d\n", maxSub);
	}

	return 0;
}