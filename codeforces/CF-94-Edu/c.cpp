#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define sint(a) scanf("%d", &a)
#define slong(a) scanf("%lld", &a);
#define mem(a, b) memset(a, b, sizeof(a))
#define iter(it, l) for(auto it = l.begin(); it != l.end(); it++)
#define MOD 1000000007
#define MAX (int) 1e9
#define PI 3.141592653589793238462643383279502884

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

int t, x, n;
string s;

int main() {

	cin >> t;
	while(t--) {
		cin >> s >> x;
		string w;
		n = s.length();
		w.resize(s.length());

		bool possible = true;
		int a = 0, b = n - 1; // pointers to beginning and end of string

		while(a <= b) {

			if(a + x == b - x) { // two elements of s effecting the same element in w
				// therefore they must not want to set w_i+x to different values
				if(s[a] != s[b]) {
					possible = false;
					break;
				} else {
					w[a + x] = s[a] == '1' ? '1' : '0';
				}
			}

			if(a + x < n) {
				w[a + x] = s[a] == '1' ? '1' : '0';
			} else if(a - x >= 0) {
				w[a - x] = s[a] == '1' ? '1' : '0';
			} else {
				possible = false;
				break;
			}

			if(b + x < n) {
				w[b + x] = s[b] == '1' ? '1' : '0';
			} else if(a - x >= 0) {
				w[b - x] = s[b] == '1' ? '1' : '0';
			} else {
				possible = false;
				break;
			}

			a++; b--;
		}

		if(possible) {
			cout << w << "\n";
		} else {
			cout << -1 << "\n";
		}
	}
	
	return 0;
}