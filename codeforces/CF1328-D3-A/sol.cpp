#include <bits/stdc++.h>

using namespace std;


int main() {

	int t, a, b, ans;
	scanf("%d", &t);
	for(int i = 0; i < t; i++) {
		scanf("%d %d", &a, &b);

		if(a <= b) {
			ans = b - a;
		} else if(a % b == 0) {
			ans = 0;
		} else {
			ans = (((a / b) + 1) * b) - a;
		}

		printf("%d\n", ans);
	}

	return 0;
}