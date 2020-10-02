#include <bits/stdc++.h>

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
ll a[100005];	

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}

	if(n == 1) {
		cout << 1 << " " << 1 << "\n";
		cout << -1 * a[0] << "\n";
		cout << 1 << " " << 1 << "\n";
		cout << 0 << "\n";
		cout << 1 << " " << 1 << "\n";
		cout << 0 << "\n";
	} else {
		cout << 1 << " " << n - 1 << "\n";
		for(int i = 0; i < n - 1; i++) {
			cout << (n - 1) * a[i] << " ";
		}
		cout << "\n";

		cout << 1 << " " << n << "\n";
		for(int i = 0; i < n - 1; i++) {
			cout << -1 * n * a[i] << " ";
		}
		cout << "0\n";

		cout << n << " " << n << "\n";
		cout << -1 * a[n - 1] << "\n";
	}

	return 0;
}