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

int t, cnt0, cnt1;
string s;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> t;
	while(t--) {

		cnt0 = 0, cnt1 = 0;

		cin >> s;
		int n = s.length();

		for(int i = 0; i < n; i++) {
			if(s[i] == '0') cnt0++;
			else cnt1++;
		}

		if(cnt0 == 0) cout << s;
		else if(cnt1 == 0) cout << s;
		else {


			for(int i = 0; i < 2 * n; i++) {
				if(i % 2 == 0) cout << '0';
				else cout << '1';
			}
		}
		cout << "\n";
	}

	return 0;
}