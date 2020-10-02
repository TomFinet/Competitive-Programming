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

int t, n, a[100005];

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> t;
	while(t--) {
		cin >> n;

		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}

		int pos = -1, neg = -1;
		for(int i = 0; i < n / 2; i++) {
			if(pos == -1) {
				if(a[i] > 0) {
					pos = i;
					continue;
				}
			}

			if(neg == -1 && pos != -1) {
				if(a[i] < 0) {
					neg = i;
				}
			}
		}

		ll cost = 0;
		bool done = false;
		bool after = true;
		while(!done) {

			ll plusCost = min(-1 * a[neg], a[pos]);

			if(pos > neg) {
				cost += plusCost;	
			}
			

			a[neg] += plusCost;
			a[pos] -= plusCost;

			while(a[pos] <= 0) {
				pos++;
				if(pos >= n) {
					done = true;
					break;
				}
			}

			if(after) {
				while(neg <= pos || a[neg] >= 0) {
					neg++;
					if(neg >= n) {
						after = false;
						neg = 0;
						break;
					}
				}
			} else {
				while(a[neg] >= 0) {
					neg++;
					if(neg >= pos) {
						done = true;
						break;
					}
				}
			}
		}

		cout << cost << "\n";

	}

	return 0;
}
