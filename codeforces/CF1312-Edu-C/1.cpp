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

string s;
int n, consec, swaps;

int main() {

	sint(n);
	cin >> s;

	for(int i = 1; i < n; i++) {
		if(s[i - 1] == s[i]) {
			consec++;
		} else {
			consec = 0;
		}

		if(consec == 3) {
			swap++;
			consec = 0;
			i++;
		}
	}

	cout << "Minimum swaps: " << swaps << "\n";
	
	return 0;
}
