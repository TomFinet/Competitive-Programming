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

int t, n, x, y;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> t;
	while(t--) {

		cin >> n >> x >> y;

		// try to fit n - 2 elements between x and y
		// try common difference of d = 1 up to d = y - x

		// try all possible start points
		// try all possible common differences
		int s[n];
		for(int d = 1; d <= y - x; d++) {
			for(int a = 1; a <= x; a++) {
				bool hasX = false, hasY = false;
				for(int i = 0; i < n; i++) {
					s[i] = a + i * d;
					if(s[i] == x) {
						hasX = true;
					} else if(s[i] == y) {
						hasY = true;
					}
				}

				if(hasX && hasY) {
					goto out;
				}
			}
		}

		
		out: for(int i = 0; i < n; i++) {
			cout << s[i] << " ";
		}
		cout << "\n";
	}

	return 0;
}