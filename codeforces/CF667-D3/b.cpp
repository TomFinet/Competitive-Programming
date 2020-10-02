#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define mem(a, b) memset(a, b, sizeof(a))

const int MOD = 1000000007;
const int MAX = (int) 1e9;
const double PI = 3.141592653589793238462643383279502884;

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
ll a, b, x, y, n;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);


	cin >> t;
	while(t--) {
		cin >> a >> b >> x >> y >> n;

		ll n1 = n;
		ll j = min(n1, a - x);
		ll a1 = a - j;
		n1 -= j;
		ll b1 = b - min(n1, b - y);
		ll prod1 = a1 * b1;

		ll n2 = n;
		j = min(n2, b - y);
		ll b2 = b - j;
		n2 -= j;
		ll a2 = a - min(n2, a - x);
		ll prod2 = a2 * b2;

		if(prod1 > prod2) {
			cout << prod2 << "\n";
		} else {
			cout << prod1 << "\n";
		}
	}

	return 0;
}