#include <bits/stdc++.h>

using namespace std;


int main() {

	int t;
	uint64_t f, l, count;
	scanf("%d", &t);

	for(int i = 1; i <= t; i++) {
		scanf("%lu %lu", &f, &l);

	 	count = 0;
		int sum;
		for(uint64_t n = f; n <= l; n++) {
			string ns = to_string(n);
			if(ns.find('9') != string::npos) {
				continue;
			}

			sum = 0;
			for(int j = 0; j < ns.length(); j++) {
				sum += ns[j] - 48;
			}
			
			if(sum % 9 == 0) {
				continue;
			}
			count++;
		}

		printf("Case #%d: %lu\n", i, count);
	}

	return 0;
}