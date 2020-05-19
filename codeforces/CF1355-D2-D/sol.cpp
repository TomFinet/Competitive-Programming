#include <bits/stdc++.h>

using namespace std;

int n, s;

int main() {

	scanf("%d %d", &n, &s);

	// checking if Petya can win
	if(s >= 2 * n) {
		printf("YES\n");
		// constructing winning array
		for(int i = 0; i < n - 1; i++) {
			printf("1 ");
		}
		printf("%d\n", s - n + 1);
		printf("%d\n", n);
	} else {
		printf("NO\n");
	}

	return 0;
}
