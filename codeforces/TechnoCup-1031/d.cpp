#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

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

int n, k, dp[2000][2000];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	if(k > 2 * n - 1) {
		for(int i = 0; i < 2 * n - 1; i++) {
			cout << "a";
		}
	} else {

		char g[n][n];

		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				cin >> g[i][j];
			}
		}

		// count the minimum number of non-a's from (0, 0) to each (i, j)
		dp[0][0] = 'a' != g[0][0] ? 1 : 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				dp[i][j] = 'a' == g[0][0] ? 1 : 0;
				dp[i][j] += min(dp[i][max(0, j - 1)], dp[max(0, i - 1)][j]);
			}
		}

		// start from (0, 0), if dp[i][j] <= k, it means the first 
		// i + j letters can be written as 'a's. Find max(i + j) 
		// such that dp[i][j] <= k.
		int maxPrefix = 0;
		int x = 0, y = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(dp[i][j] <= k){
					if(maxPrefix < i + j) {
					maxPrefix = i + j;
					x = i; y = j;
				}
			}
		}

		string ans;
		for(int i = 0; i < x + y; i++) {
			ans.append('a');
		}

		// from (x, y) we pick the smallest string.
		while(x < n || y < n) {
			if(g[x][y + 1] < g[x + 1][y]) {
				y++;
			} else {
				x++;
			}
			ans.append(g[x][y]);
		}

	}

	return 0;

}