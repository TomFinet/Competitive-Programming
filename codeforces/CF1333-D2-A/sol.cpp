#include <bits/stdc++.h>

using namespace std;

int t, n, m;

int main() {

	scanf("%d", &t);
	for(int ti = 0; ti < t; ti++) {
		scanf("%d %d", &n, &m);

		for(int r = 0; r < n - 1; r++) {
			for(int c = 0; c < m; c++) {
				printf("B");
			}
			printf("\n");
		}

		for(int c = 0; c < m - 1; c++) {
			printf("B");
		}
		printf("W\n");
	}

	return 0;
}