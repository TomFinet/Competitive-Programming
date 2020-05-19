#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define sint(a) scanf("%d", &a)
#define slong(a) scanf("%lld", &a);
#define mem(a, b) memset(a, b, sizeof(a))
#define iter(l) for(auto it = l.begin(); it != l.end(); it++)
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

int q, pos2, pos0;
ll n, tmpN, ans, power3;
bool good;
vi ternary;

int main() {

	sint(q);
	while(q--) {

		scanf("%lld", &n);

		pos2 = -1, pos0 = -1;
		good = true;
		tmpN = n;
		for(int i = 0; tmpN > 0; i++) {
			ternary.push_back(tmpN % 3);
			if(tmpN % 3 == 2) {
				pos2 = i;
				good = false;
			}

			tmpN /= 3;
		}

		if(pos2 != -1) { // 2s found in base 3 representation of n
			for(int i = pos2 + 1; i < ternary.size(); i++) {
				if(ternary[i] == 0) {
					pos0 = i;
					break;
				}
			}

			if(pos0 == -1) {
				ternary.push_back(0);
				pos0 = ternary.size() - 1;
			}
		}

		if(good) {
			printf("%lld\n", n);
		} else {
			ternary[pos0] = 1;

			power3 = 1;
			for(int i = 0; i < pos0; i++) {
				ternary[i] = 0;
				power3 *= 3;
			}

			ans = 0;
			for(int i = pos0; i < ternary.size(); i++) {
				ans += ternary[i] * power3;
				power3 *= 3;
			}

			printf("%lld\n", ans);
		}

		ternary.clear();
	}
	
	return 0;
}