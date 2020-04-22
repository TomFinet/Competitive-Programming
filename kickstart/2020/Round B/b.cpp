#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

template <typename T, typename U>
T max(T x, U y) {
    return x > y ? x : y;
}

template <typename T, typename U>
T min(T x, U y) {
    return x < y ? x : y;
}

int t, n;
ll d;

int main() {

	scanf("%d", &t);
	for(int ti = 1; ti <= t; ti++) {
		scanf("%d %lld", &n, &d);

		int x[n], latest[2];
		for(int i = 0; i < n; i++) {
			scanf("%d", &x[i]);
		}

		int l = 1, r = (int) floor(d / (double)x[0]), m;
		while(l <= r) {
			m = (l + r) / 2;
			
			latest[0] = m * x[0];
			for(int i = 1; i < n; i++) {
				latest[1] = (int) (ceil(latest[0] / (double)x[i]) * x[i]);
				latest[0] = latest[1];
			}

			if(latest[0] > d) {
				r = m - 1;
			} else {
				l = m + 1;
			}
		}

		printf("Case #%d: %d\n", ti, (l - 1) * x[0]);
	}

	return 0;
}