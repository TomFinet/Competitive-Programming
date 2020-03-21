#include <bits/stdc++.h>

using namespace std;


int main() {

	int t;
	uint64_t n;
	scanf("%d", &t);


	for(int i = 1; i <= t; i++) {
		scanf("%lu", &n);

		vector<int> v;
		v.reserve(16);
		uint64_t tmpn = n;
		while(tmpn > 0) {
			int d = tmpn % 10;
			v.push_back(d);
			tmpn /= 10;
		}

		uint64_t p = 0;
		for(int d = v.size() - 1; d >= 0; d--) {
			if(v[d] % 2 == 0) {
				continue; 
			}

			if(d == 0) {
				p = 1;
				break;
			}

			// build n
			uint64_t compn = 0;
			for(int j = 0; j <= d; j++) {
				compn += ((int) pow(10, j)) * v[j];
				cout << "compn: " << compn << "\n";
			}

			uint64_t larger = ((int) pow(10, d)) * (v[d] + 1);
			// fill array with 888888 until end for smaller
			// convert to int after.
			uint64_t smaller = 0;
			for(int j = 0; j < d; j++) {
				smaller += ((int) pow(10, j)) * 8;
			}
			smaller += ((int) pow(10, d)) * (v[d] - 1);

			cout << "smaller: " << smaller << "\n";
			cout << "larger: " << larger << "\n";
			uint64_t downP = compn - smaller;
			uint64_t upP = larger - compn;
			cout << "n: " << n << "\n";
			cout << "compn: " << compn << "\n";
			cout << "downP: " << downP << "\n";
			cout << "upP: " << upP << "\n";
			p = min(downP, upP);

			break;
		}

		printf("Case #%d: %lu", i, p);
	} 

	return 0;
}