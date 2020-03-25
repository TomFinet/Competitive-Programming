#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, bi;
unordered_map<ll, ll> sums;
ll maxSum;

int main() {

	scanf("%d", &n);

	for(int i = 0; i  < n; i++) {
		scanf("%d", &bi);
		sums[bi- i] += bi;
	}

	for(auto p : sums) {
		maxSum = max(maxSum, p.second);
	}

	printf("%llu\n", maxSum);

	return 0;
}