#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

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

int t, xa, ya, za, xb, yb, zb, res;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	while(t--) {

		cin >> xa >> ya >> za >> xb >> yb >> zb;

		res = 0;

		// maximize (za, yb) = (2, 1)
		// minimize (ya, zb) = (1, 2) by maximizing (xa, zb) = (0, 2)
		// and maximizing (ya, xb) = (1, 0)

		int goodPairs = min(za, yb); // for (2, 1) where coord is form (a, b)
		res = goodPairs * 2;
		za -= goodPairs; yb -= goodPairs;

		// pair 0s in a with 2s in b as much as possible		
		int zeroPairs = min(xa, zb); // for (0, 2)
		xa -= zeroPairs; zb -= zeroPairs;

		// pair 1s in a with 0s in b
		zeroPairs = min(ya, xb); // for (1, 0)
		ya -= zeroPairs; xb -= zeroPairs;

		// pair remaining 1s in a with 2s in b
		int badPairs = min(ya, zb);
		res -= badPairs * 2;

		cout << res << "\n";

	}

	return 0;

}