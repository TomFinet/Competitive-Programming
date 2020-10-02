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

int R, G, B;

int main() {

	scanf("%d %d %d", &R, &G, &B);
	
	int r[R], g[G], b[B];

	for(int i = 0; i < R; i++) { sint(r[i]); }
	for(int i = 0; i < G; i++) { sint(g[i]); }
	for(int i = 0; i < B; i++) { sint(b[i]); }

	sort(r, r + R);
	sort(g, g + G);
	sort(b, b + B);

	// let dp[r][g][b] = maximum area chosing r red sticks,
	// g green sticks and b blue sticks.

	int pr = R - 1; // pointing to largest element in each array
	int pg = G - 1;
	int pb = B - 1;

	for(int i = 0; i <= R; i++) {
		for(int j = 0; j <= G; j++) {
			for(int k = 0; k <= B; k++) {

				if(i + j != k && i + k != j && j + k != i) {
					continue; // invalid selected sticks
				}

				while(!(pr == -1 && pb == -1) || (pg == -1 && pb == -1) || (pr == -1 && pg == -1)) {

					int minVal = min(min(r[pr], g[pg]), b[pb]);

					if(minVal == r[pr]) {
						area += g[pg] * b[pb];
						pg--; pb--;
					}

					if(minVal == g[pr]) {
						area += r[pr] * b[pb];
						pr--; pb--;
					}

					if(minVal == b[pr]) {
						area += g[pg] * r[pr];
						pg--; pr--;
					}
				}
			}
		}
	}

	

	printf("%d\n", area);

	
	return 0;
}