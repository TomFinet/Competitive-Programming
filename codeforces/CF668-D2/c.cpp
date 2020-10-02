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

inline int abs(int a, int b) { return a > b ? a - b : b - a; }

int t, n, k;
string s;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> t;
	while(t--) {
		cin >> n >> k >> s;

		bool possible = true;
		for(int i = 0; i < n; i++) {
			if(s[i] == '0' && s[i % k] == '1')  possible = false;
			else if(s[i] == '1' && s[i % k] == '0') possible = false;
			else if(s[i] != '?' && s[i % k] == '?') s[i % k] = s[i];
			else if(s[i] == '?' && s[i % k] != '?') s[i] = s[i % k];
		}

		int cnt0 = 0, cnt1 = 0;
		for(int i = 0; i < k; i++) {
			if(s[i] == '0') cnt0++;
			else if(s[i] == '1') cnt1++;
		}

		if(2 * cnt0 > k || 2 * cnt1 > k) possible = false;

		if(possible) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}
