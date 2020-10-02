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

int t, x, n;
string s;
bool possible;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> t;
	while(t--) {

		cin >> s >> x;

		n = s.length();
		string w(n, '1');

		for(int i = 0; i < n; i++) {
			if(s[i] == '1') continue;
			if(i >= x) w[i - x] = '0';
			if(i + x < n) w[i + x] = '0';
		}

		possible = true;
		for(int i = 0; i < n; i++) {
			if(s[i] == '1') {
				if(i >= x && w[i - x] == '1') continue;
				if(i + x < n && w[i + x] == '1') continue;
				possible = false;
				break;
			}
		}

		if(possible) cout << w << "\n";
		else cout << -1 << "\n";

	}

	return 0;
}