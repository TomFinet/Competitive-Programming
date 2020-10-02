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

int t, p, f, cnts, cntw, s, w;

int main() {

	cin >> t;
	while(t--) {
		cin >> p >> f >> cnts >> cntw >> s >> w;

		// A and B are the people
		// we know that A can 0 to cnts swords.
		// lets try each combination with brute force

		int maxWeapons = 0;

		for(int snA = 0; snA <= min(cnts, p / s); snA++) {
			int wnA = min(cntw, (p - snA * s) / w); // war-axe number = unused mass / war axe mass

			// allocate greedily the remaining swords and axes to B
			int snB, wnB;
			if(s < w) {
				snB = min(cnts - snA, f / s);
				wnB = min(cntw - wnA, (f - snB * s) / w);
			} else {
				wnB = min(cntw - wnA, f / w);
				snB = min(cnts - snA, (f - wnB * w) / s);
			}
			maxWeapons = max(maxWeapons, snA + snB + wnA + wnB);
		}

		cout << maxWeapons << "\n";
	}	
	
	return 0;
}