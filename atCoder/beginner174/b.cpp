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

int toDigit(char c) { return c - '0'; }

int n, ans;
ll x, y, d;

int main() {

	cin >> n >> d;
	d *= d;

	for(int i = 0; i < n; i++) {
		cin >> x >> y;
		if((x * x) + (y * y) <= d) {
			ans++;
		}
	}

	cout << ans << "\n";
	
	return 0;
}