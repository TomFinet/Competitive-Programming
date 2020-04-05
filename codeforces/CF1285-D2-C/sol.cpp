#include <bits/stdc++.h>

using namespace std;

int x;

int main() {

	scanf("%d", &x);
	
	int a = x;
	int b = 1;
	for(int i = 2; i * i < x; i++) {
		if(x % i == 0 && lcm(i, x / i) == x) {
			a = min(a, x / i);
		}
	}

	printf("%d %d\n", x / a, a);

	return 0;
}