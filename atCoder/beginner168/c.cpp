#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define mem(a, b) memset(a, b, sizeof(a))
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

template<typename T>
T abs(T a, T b) {
	return a > b ? a - b : b - a;
}

inline int toDigit(char c) { return c - '0'; }

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0); 

	long double a, b, h, m;
	cin >> a >> b >> h >> m;
	long double d2;

	d2 = a * a + b * b - 2.0 * a * b * cos(PI * (h / 6.0 + (m / 360.0) - m / 30.0));

	cout << fixed;
	cout << setprecision(20);
	cout << sqrtl(d2) << "\n";
	

	return 0;
}