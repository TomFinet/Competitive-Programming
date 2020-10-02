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

int t, n;

int main() {

	sint(t);
	while(t--) {

		sint(n);
		int a[n];

		for(int i = 0; i < n; i++) {
			sint(a[i]);
		}

		// when playing optimally, either all or all but 1 stones are removed. 

		// assume p1 wins => p1 removes last pile.
		int currP = 0; // 0 : p1 | 1 : p2
		for(int i = n - 2; i >= 0; i--) {
			if(a[i] == 1) currP = (currP + 1) % 2;

			if(currP == 1 && a[i] > 1) { // p2 played last
				currP = 0;
			}
		}

		if(currP == 0) {
			printf("First\n");
		} else {
			printf("Second\n");
		}

	}

	return 0;

}