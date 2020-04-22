#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int t, n, x, ans;
ll s;

int main() {

	scanf("%d", &t);
	for(int ti = 0; ti < t; ti++) {
		scanf("%d %d", &n, &x);
		int a[n];

		s = 0;
		for(int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			s += a[i];
		}

		sort(a, a + n);

		ans = 0;
		for(int i = n - 1; i >= 0; i--) {
			if(s / (i + 1) >= x) {
				ans = i + 1;
				break;
			}
			s -= a[n - i - 1];
		}

		printf("%d\n", ans);
	}

	return 0;
}