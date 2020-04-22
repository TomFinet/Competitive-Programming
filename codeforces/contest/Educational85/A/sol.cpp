#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int t, n, p, c, prevP, prevC;
bool yes;

int main() {

	scanf("%d", &t);
	for(int ti = 0; ti < t; ti++) {
		scanf("%d", &n);
		
		yes = true;

		scanf("%d %d", &p, &c);
		if(c > p) {
			yes = false;
		}
		
		for(int i = 1; i < n; i++) {
			prevP = p;
			prevC = c;
			scanf("%d %d", &p, &c);
			
			if(c > p || prevC > c || prevP > p) {
				yes = false;
			} else if(prevP == p && prevC < c) {
				yes = false;
			}
		}

		if(yes) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}

	return 0;
}