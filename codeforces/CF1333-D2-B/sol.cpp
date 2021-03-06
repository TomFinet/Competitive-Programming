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

int t, n, a[100000], b[100000];

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0); 

	cin >> t;
	while(t--) {

		cin >> n;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}

		for(int i = 0; i < n; i++) {
			cin >> b[i];
		}

		bool hasPos = false, hasNeg = false, possible = true;
		for(int i = 0; i < n; i++) {
			if(a[i] < b[i] && !hasPos) {
				// needs to increase so we need a 1 in any spot from [0, i - 1]
				cout << "NO\n";
				possible = false;
				break;
			} else if(a[i] > b[i] && !hasNeg) {
				// needs to decrease so we need a -1 in any spot from [0, i - 1]
				cout << "NO\n";
				possible = false;
				break;
			}

			if(a[i] == 1) { hasPos = true; }
			if(a[i] == -1) { hasNeg = true; }
		}

		if(possible) {
			cout << "YES\n";
		}
	}


	return 0;
}