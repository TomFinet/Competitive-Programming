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

unordered_set<int> f;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0); 

	int x, n, p;
	cin >> x >> n;

	for(int i = 0; i < n; i++) {
		cin >> p;
		f.emplace(p);
	}

	int ans = 0;
	for(int d = 0; d <= 100; d++) {
		if(f.count(x - d) == 0) {
			ans = x - d;
			break;
		} else if(f.count(x + d) == 0) {
			ans = x + d;
			break;
		}
	}

	cout << ans << "\n";

	return 0;
}