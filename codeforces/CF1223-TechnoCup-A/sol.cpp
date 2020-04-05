#include <bits/stdc++.h>

using namespace std;


int main() {

	int k, n;
	scanf("%d", &k);

	for(int i = 0; i < k; i++) {
		scanf("%d", &n);

		if(n <= 4) {
			printf("%d\n", 4 - n);
			continue;
		} else if(n % 2 == 0) {
			printf("0\n");
			continue;
		} else {
			printf("1\n");
			continue;
		}
	}

	return 0;
}