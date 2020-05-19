#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define sint(a) scanf("%d", &a)
#define slong(a) scanf("%lld", &a);
#define mem(a, b) memset(a, b, sizeof(a))
#define iter(it, l) for(auto it = l.begin(); it != l.end(); it++)
#define MOD 1000000007
#define MAX (int) 1e9
#define PI 3.141592653589793238462643383279502884

template<typename T, typename U>
T max(T x, U y) {
    return x > y ? x : y;
}

template<typename T, typename U>
T min(T x, U y) {
    return x < y ? x : y;
}

template<typename T>
T abs(T x) {
	return x > 0 ? x : -1 * x; 
}

template<typename T>
void debug(string msg, T t) {
	cout << msg << ": " << t << "\n";
}

int toDigit(char c) { return c - '0'; }

int t, n, k, minOps, ops;

int main() {

	sint(t);
	while(t--) {
		scanf("%d %d", &n, &k);
		int a[n], sums[n / 2];
		for(int i = 0; i < n; i++) { sint(a[i]); }

		for(int i = 0; i <= n / 2; i++) {
			sums[i] = a[i] + a[n - i - 1];
		}

		minOps = n;
		for(int x = 2; x <= 2 * k; x++) { // each possible x
			ops = 0;
			for(int i = 0; i <= (n / 2) - 1; i++) { // go through all sums
				if(sums[i] == x) { continue; }

				int min1 = min(a[i], a[n - i - 1]) + 1;
				int max1 = max(a[i], a[n - i - 1]) + k;
				
				if(min1 <= x && x <= max1) { // only one elem needs changing
					ops++;
				} else if(x < min1 || x > max1) {
					ops += 2;
				} else {
					break;
				}
			}
			minOps = min(minOps, ops);
		}

		printf("%d\n", minOps);
	}
	
	return 0;
}
