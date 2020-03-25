#include <bits/stdc++.h>

using namespace std;


int main() {

	int t, n, b;
	scanf("%d", &t);

	for(int ti = 1; ti <= t; ti++) {
		scanf("%d %d", &n, &b);

		vector<int> h;
		h.reserve(n);
		int hi;
		for(int i = 0; i < n; i++) {
			scanf("%d", &hi);
			h.push_back(hi);
		}

		sort(h.begin(), h.end());

		int ans = 0;
		for(int i = 0; i < n; i++) {
			if(b >= h[i]) {
				b -= h[i];
				ans++;
			} else {
				break;
			}
		}

		printf("Case #%d: %d\n", ti, ans);
	}

	return 0;
}