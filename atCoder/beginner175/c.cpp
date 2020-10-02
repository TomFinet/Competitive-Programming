#include <bits/stdc++.h>

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

int toDigit(char c) { return c - '0'; }

ll x, k, d, ans;

int main() {

	cin >> x >> k >> d;

	x = x < 0 ? -1 * x : x; // symmetric so doesn't matter 
	// if x is positive or negative

	ll moveToNeg = (x / d) + 1;
	if(moveToNeg >= k) {
		ans = x - k * d;
	} else {

		k -= moveToNeg;
		if(k % 2 == 0) {
			ans = x - moveToNeg * d;
		} else {
			ans = x - (moveToNeg - 1) * d;
		}
	}

	if(ans < 0) {
		ans *= -1;
	}

	cout << ans << "\n";

	return 0;
}