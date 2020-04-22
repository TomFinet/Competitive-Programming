#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int t, n;

int main() {

	scanf("%d", &t);

	while(t--) {
		scanf("%d", &n);
		int a[n];

		for(int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}

		sort(a, a + n);

		int i = (n - 1) / 2;
		int j = ((n - 1) / 2) + 1;
		while(j < n) {
			printf("%d %d ", a[i--], a[j++]);
		}

		if(n % 2 == 1) {
			printf("%d\n", a[0]);
		}

		printf("\n");
	}

	return 0;
}