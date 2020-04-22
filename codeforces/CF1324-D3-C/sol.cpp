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

int t, n, d, lastR;
string s;

int main() {

	sint(t);
	while(t--) {

		cin >> s;
		n = s.size();

		lastR = -1, d = 0;
		for(int i = 0; i < n; i++) {
			if(s[i] == 'R') {
				d = max(d, i - lastR);
				lastR = i;
			}
		}

		printf("%d\n", max(d, n - lastR));
	}

	return 0;
}