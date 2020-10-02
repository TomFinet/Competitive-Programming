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

		int cnt0 = 0, cnt1 = 0;
		for(int i = 0; i < n; i++) {
			if(a[i] == 0) cnt0++;
			else if(a[i] == 1) cnt1++;
		}

		if(cnt1 <= n / 2) {
			// remove all 1s and possibly some 0s
			cout << n / 2 << "\n";
			for(int i = 0; i < n / 2; i++) cout << "0 ";
		} else {
			if(cnt1 % 2 == 0) {
				// remove all 0s
				cout << cnt1 << "\n";
				for(int i = 0; i < cnt1; i++) cout << "1 ";
			} else {
				// remove all 0s and one 1
				cout << cnt1 - 1 << "\n";
				for(int i = 0; i < cnt1 - 1; i++) cout << "1 ";
			}
		}

		cout << "\n";

	}

	return 0;
}
