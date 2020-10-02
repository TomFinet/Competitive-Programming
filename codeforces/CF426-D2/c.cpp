#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define mem(a, b) memset(a, b, sizeof(a))

const int MOD = 1000000007;
const double PI = 3.141592653589793238462643383279502884;
const ll INF = 1e18;

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

inline int toDigit(char c) { return c - '0'; }

int n;
ll a, b;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	while(n--) {

		cin >> a >> b;

		// we know a*b must be a perfect cube
		// and cuberoot(ab) must divide a and b

		ll prod = a * b;

		ll l = 0, r = 1000000, m = 0;
		while(l <= r) {
			m = l + (r - l) / 2;
			ll cube = m * m * m;

			if(cube > prod) {
				r = m - 1;
			} else if(cube < prod) {
				l = m + 1;
			} else {
				break;
			}
		}

		if(m * m * m != prod) {
			cout << "NO\n";
		} else if(a % m == 0 && b % m == 0) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

	return 0;
}