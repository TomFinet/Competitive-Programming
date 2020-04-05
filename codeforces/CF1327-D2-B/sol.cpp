#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int t, n, k, g, unmarried;

int main() {

	scanf("%d", &t);
	for(int a = 0; a < t; a++) {
		scanf("%d", &n);

		int takenPrinces[n] = {0};
		unmarried = -1;

		for(int i = 0; i < n; i++) {
			scanf("%d", &k);
			bool stillUnmarried = true;
			for(int j = 0; j < k; j++) {
				scanf("%d", &g);
				if(takenPrinces[g - 1] == 0 && stillUnmarried) {
					// prince is available to ith princess.
					takenPrinces[g - 1] = 1;
					stillUnmarried = false;
				}
			}

			if(stillUnmarried) {
				unmarried = i + 1; 
			}
		}

		if(unmarried == -1) {
			printf("OPTIMAL\n");
		} else {
			for(int i = 0; i < n; i++) {
				if(takenPrinces[i] == 0) {
					printf("IMPROVE\n");
					printf("%d %d\n", unmarried, i + 1);
					break;
				}
			}
		}
	}
	
	return 0;
}