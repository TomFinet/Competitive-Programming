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

int n, m, a[200005];

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> a[i];

	sort(a, a + n);
	
	ll s[200005]; s[0] = a[0];
	for(int i = 1; i < n; i++) s[i] = a[i] + s[i - 1];
	
	ll x[200005]; // answers for each k
	for(int k = 1; k <= n; k++) {
		if(k <= m) {
			x[k - 1] = s[k - 1];
		} else {
			x[k - 1] = s[k - 1] + x[k - m - 1];
		}
	}

	for(int i = 0; i < n; i++) {
		cout << x[i] << " ";
	}
	cout << "\n";

	return 0;
}
