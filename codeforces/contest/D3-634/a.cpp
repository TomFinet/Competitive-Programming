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

int main() {

	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		if(n % 2 == 0) {
			printf("%d\n", (n / 2) - 1);
		} else {
			printf("%d\n", n / 2);
		}

	}

	return 0;
}