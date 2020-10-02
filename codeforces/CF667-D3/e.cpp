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

int t, n, k;
int x[200000], y[200000];

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> t;
	while(t--) {

		cin >> n >> k;

		for(int i = 0; i < n; i++) cin >> x[i];
		for(int i = 0; i < n; i++) cin >> y[i];

		sort(x, x + n);

		// place the platforms at y = -1
		// then all points no point can be below them

		// where to place the platforms horizontally?
		// platforms should not overlap
		// so we call one the left platform, and the other the right

		
	}

	return 0;
}