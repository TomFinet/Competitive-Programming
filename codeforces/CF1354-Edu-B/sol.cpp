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
int n;

unordered_set<int> seen;

int calc(int max, int l) {

	for(int i = 3; i < max; i++) {
		if(s[l - i])


		seen.emplace();
	}

}

int main() {

	cin >> s;
	scanf("%d", &n);

	int dp[n + 1];

	dp[2] = -1;

	for(int l = 3; l <= n; l++) {
		dp[l] = calc(dp[l - 1], l);
	}

	return 0;
}