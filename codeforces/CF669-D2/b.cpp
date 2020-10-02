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

int t, n, a[1005];

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> t;
	while(t--) {

		cin >> n;
		
		for(int i = 0; i < n; i++) cin >> a[i];

		// for lexographically largest number
		// we need to maximize the value of c_1
		// the we maximize the value of c_i
		// c_i = gcd(b_1, ..., b_i)

		// Observation: 
		// gcd(b_1, ..., b_i, b_(i+1)) = gcd(gcd(b_1, ..., b_i), b_i+1)

		bool used[1005] = {0};
		int b[1005];
		int c = 0;
		for(int i = 1; i <= n; i++) {
			idx = 0;
			for(int j = 0; j < n; j++) {
				if(used[j]) continue;

				int gcd = __gcd(c, a[j]);
				if(c < gcd) {
					c = gcd;
					idx = j;
				}
			}

			b[i - 1] = a[idx];
			used[idx] = true;
		}


		for(int i = 0; i < n; i++) {
			cout << b[i] << " ";
		}
		cout << "\n";
		
	}

	return 0;
}
