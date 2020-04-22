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

int t, n, m;

int main() {

	scanf("%d", &t);
	while(t--) {

		m = 0;

		scanf("%d", &n);
		int a[n];
		int color[n];

		for(int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}

		for(int i = 0; i < n; i++) {
			bool coprime = true;
			for(int j = 0; j < i; j++) {
				if(__gcd(a[i], a[j]) > 1) {
					color[i] = color[j];
					coprime = false;
					break;
				}
			}

			if(coprime) {
				color[i] = ++m;
			}
		}

		printf("%d\n", m);
		for(int i = 0; i < n; i++) {
			printf("%d ", color[i]);
		}
		printf("\n");

	}

	return 0;
}