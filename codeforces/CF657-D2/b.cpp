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

int t;
ll l, r, m;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> t;
	while(t--) {

		cin >> l >> r >> m;

		ll a, b, c;

		for(a = l; a <= r; a++) {
			ll n = m / a;
			ll rem = m - n * a;
			// we know b - c is within [l - r, r - l]
			if(rem > (n + 1) * a - m || n == 0) {
				rem = m - (n + 1) * a;
			}

			if(rem <= r - l && rem >= 0) c = l;
			else if(rem >= l - r && rem < 0) c = r;
			else continue;

			b = c + rem;
			break;
		}

		cout << a << " " << b << " " << c << "\n";

	}

	return 0;
}