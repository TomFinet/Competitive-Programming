#include <bits/stdc++.h>

using namespace std;

long long x;

long long lcm(long long a, long long b) {
	return (a * b) / __gcd(a, b);
}

int main() {

	scanf("%lld", &x);
	
	long long a = x;
	for(long long i = 2; i * i < x; i++) {
		if(x % i == 0 && lcm(i, x / i) == x) {
			a = i;
		}
	}

	printf("%lld %lld\n", x / a, a);

	return 0;
}