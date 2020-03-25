#include <bits/stdc++.h>

using namespace std;

int t, n;
bool no;

int main() {

	scanf("%d", &t);
	for(int i = 1; i <= t; i++) {
		scanf("%d", &n);

		int a[n];
		for(int j = 0; j < n; j++) {
			scanf("%d", &a[j]);
		}

		no = false;
		for(int j = 1; j < n; j++) {
			if(abs(a[0] - a[j]) % 2 == 1) {
				no = true;
				break;
			}
		}

		if(no) {
			printf("NO\n");
		} else {
			printf("YES\n");
		}
	}

	return 0;
}