#include <bits/stdc++.h>

using namespace std;

int main() {

	int t, n, k;
	scanf("%d", &t);
	for(int i = 0; i < t; i++) {
		scanf("%d %d", &n, &k);
		
		int j;
		for(j = 1; j <= n; j++) {
			if(k - j <= 0) {
				break;
			} 
			k -= j;
		}

		string out;
		for(int o = n; o > 0; o--) {
			if(o == j + 1 || k == o) {
				out.append("b");
			} else {
				out.append("a");
			}
		}

		cout << out << endl;
	}

	return 0;
}