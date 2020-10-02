#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define mem(a, b) memset(a, b, sizeof(a))
#define MOD 1000000007
#define MAX (int) 1e9
#define PI 3.141592653589793238462643383279502884

template <typename T, typename U>
T max(T x, U y) {
    return x > y ? x : y;
}

template <typename T, typename U>
T min(T x, U y) {
    return x < y ? x : y;
}

template<typename T>
void debug(string msg, T t) {
	cout << msg << ": " << t << "\n";
}

template<typename T>
T& abs(T& a, T& b) {
	return a > b ? a - b : b - a;
}

inline int toDigit(char c) { return c - '0'; }

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0); 

	int n, m, x;
	cin >> n >> m >> x;
	int c[n], a[n][m];
	
	for(int i = 0; i < n; i++) {
		cin >> c[i];
		for(int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	int minCost = -1;

	// iterate through all combinations of books.
	for(int mask = 0; mask < (1 << n); mask++) {
		int cost = 0;
		int u[m] = {0}; // understanding of algorithms
		for(int i = 0; i < n; i++) {
			if(((1 << i) & mask) == 0) {
				continue;
			}

			for(int j = 0; j < m; j++) {
				u[j] += a[i][j];
			}

			cost += c[i];
		}
		
		bool good = true;
		for(int j = 0; j < m; j++) {
			if(u[j] < x) { good = false; break; }
		}

		if(good) {
			minCost = minCost == -1 ? cost : min(minCost, cost);
		}
	}

	cout << minCost << "\n";

	return 0;
}