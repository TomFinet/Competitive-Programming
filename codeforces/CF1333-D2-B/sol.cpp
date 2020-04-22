#include<bits/stdc++.h>

using namespace std;

int t, n;

int main() {

	scanf("%d", &t);
	for(int ti = 0; ti < t; ti++) {
		scanf("%d", &n);
		int a[n], b[n];
		for(int i = 0; i < n; i++) { scanf("%d", &a[i]); }
		for(int i = 0; i < n; i++) { scanf("%d", &b[i]); }
		

		// for b[i] if there is a number a[k] (0 <= k < i) 
		// which has the same and parity sign as b[i]

		if(a[0] != b[0]) {
			printf("NO\n");
		} else {
			bool was1 = false, wasMinus1 = false, yes = true;
			for(int i = 1; i < n; i++) {
				if(a[i - 1] == 1) {
					was1 = true;
				} else {
					was1 = false;
				}

				if(a[i - 1] == -1) {
					wasMinus1 = true;
				} else {
					wasMinus1 = false;
				}

				if(a[i] < b[i] && !was1) {
					printf("NO\n");
					yes = false;
				} else if(a[i] > b[i] && !wasMinus1) {
					printf("NO\n");
					yes = false;
				}
			}

			if(yes) {
				printf("YES\n");
			}
		}

	}


	return 0;
}