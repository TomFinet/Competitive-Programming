#include <bits/stdc++.h>

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

int toDigit(char c) { return c - '0'; }

string s, t;
int ans = MAX, diff;

int main() {

	cin >> s >> t;

	int n = s.length();
	int m = t.length();

	for(int i = 0; i <= n - m; i++) {
		diff = 0;
		for(int j = 0; j < m; j++) {
			if(s[i + j] != t[j]) {
				diff++;
			}
		}

		if(diff < ans) {
			ans = diff;
		}
	}

	cout << ans << "\n";

	return 0;
}