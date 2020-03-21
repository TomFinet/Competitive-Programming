#include <bits/stdc++.h>

using namespace std;

int t, n, k, a, b, c;

vector<vector<int>> solve(int bin[]) {

}

vector<int> gen(int i) {
	
}

int main() {
	uint64_t p;
	scanf("%d", &t);

	for(int i = 1; i <= t; i++) {
		scanf("%d %d %lu", &n, &k, &p);
		int bin[n] = {-1};
		for(int j = 0; j < k; j++) { 
			scanf("%d %d %d", &a, &b, &c);
			bin[a] = c;
		}

		vector<vector<int>> bbs;
		vector<int> bs;
		for(int i = 0; i < n; i++) {
			if(bin[i] != -1) {
				// add gen(i - 1) to bs
				// add bin[i] to end of bs
				
			}
		}

	}

	// small input makes sure bit is set in pos A_i
	// generate smallest possible binary string up to i
	// generate smallest possible

	


	return 0;
}