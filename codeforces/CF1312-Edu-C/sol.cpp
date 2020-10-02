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

int toDigit(char c) { return c - '0'; }

int t, n, k;
ll a[30];
bool isPossible;

int main() {

	// start from A
	// try to get to array of 0
	// each iteration, zero or one pos should be available
	// if more than one is available then it is impossible.

	sint(t);
	while(t--) {
		isPossible = true;
		scanf("%d %d", &n, &k);
		for(int i = 0; i < n; i++) { 
			slong(a[i]);
		}

		// start from the max possible iteration
		// ith iteration has k^i which is at most
		// floor(16 * log_{k}{10})

		int iter = (int)(16 / log10(k));
		for(int i = iter; i >= 0; i--) { // each iteration
			int posCount = 0;
			for(int j = 0; j < n; j++) { // each element in A
				int greatestPower = (int)pow(k, i);
				if(a[j] >= greatestPower) {
					printf("poscount: %d\n", posCount);
					a[j] -= greatestPower;
					posCount++;
				}
			}

			if(posCount > 1) {
				isPossible = false;
				break;
			}
		}

		for(int j = 0; j < n; j++) {
			if(a[j] > 0) { isPossible = false; break; }
		}
			
		if(isPossible) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}

	}
	
	return 0;
}
