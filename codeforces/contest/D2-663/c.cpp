#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int tc, n, prevA, a, t;

int main() {

	scanf("%d", &tc);
	while(tc--) {

		scanf("%d", &n);
		scanf("%d", &prevA);
		t = 0;
		for(int i = 1; i < n; i++) {
			scanf("%d", &a);
			if(a < prevA) {
				int add = 0, maxK = 0;
				while(true) {
					if(pow(2, maxK) > (prevA - a)) {
						break;
					}
					maxK++;
				}
				t = max(t, maxK);
			} else {
				prevA = a;
			}	
		}

		printf("%d\n", t);
	}

	return 0;
}