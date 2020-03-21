#include <bits/stdc++.h>

using namespace std;

int main() {

	int t, n;
	scanf("%d", &t);

	for(int i = 1; i <= t; i++) {
		scanf("%d", &n);
		int nums[n];
		for(int j = 0; j < n; j++) { scanf("%d", &nums[j]); }

		int maxS = nums[0];
		int maxAtJ[n];
		maxAtJ[0] = maxS;
		for(int j = 1; j < n; j++) {
			maxS = max(maxS + nums[j], nums[j]);
			maxAtJ[j] = maxS;
		}

		maxS = maxAtJ[0];
		for(int j = 1; j < n; j++) {
			maxS = max(maxS, maxAtJ[j]);
		}

		printf("Case #%d: %d\n", i, maxS);

	}

	return 0;
}