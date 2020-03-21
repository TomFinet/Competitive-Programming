#include <bits/stdc++.h>

using namespace std;

vector<int> v;
int n;

double expected(int k) {
	double exp = 0;

	if(k == 0) { 
		for(int i = 0; i < n; i++) {
			exp += (double) v[i];
		}
		exp /= (double) n;
	} else {
		double expPrevK = expected(k - 1);
		for(int i = 0; i < n; i++) {
			exp += max((double)v[i], expPrevK);
		}
		exp /= (double) n;
	}

	return exp;
}

int main() {

	int t, k;
	scanf("%d", &t);

	for(int ti = 1; ti <= t; ti++) {
		scanf("%d %d", &n, &k);

		v.clear();
		int vi;
		for(int i = 0; i < n; i++) { 
			scanf("%d", &vi);
			v.push_back(vi);	
		}

		printf("Case #%d: %.6f\n", ti, expected(k));
	}

	return 0;
}