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

int t, s;
ll n;

ll binpow(ll a, ll b) {
	ll res = 1;

	while(b > 0) {
		if(b & 1) {
			res *= a;
		}

		b >>= 1; // div by 2
		a *= a;
	}

	return res;
}	


int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> t;
	while(t--) {

		cin >> n >> s;

		int num[20] = {0};
		int dSum = 0, i = 0;
		while(n > 0) {
			int d = n % 10;
			dSum += d;
			num[i] = d;
			
			n /= 10;
			i++;
		}

		if(dSum <= s) {
			cout << 0 << "\n";
		} else {
			int sum = 0;
			while(sum + num[i] < s) {
				sum += num[i];
				i--;
			}

			// take ith digit multiply by digits place
			// subtract from remainder of number

			// change ith digit to a higher value
			ll tenpow = binpow(10, i + 1);
			ll moves = tenpow;

			for(int j = i; j >= 0; j--) {
				tenpow /= 10;
				moves -= num[j] * tenpow;
			}

			cout << moves << "\n";
		}

	}

	return 0;
}