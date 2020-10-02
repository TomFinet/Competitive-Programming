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

int t, n, x, y, cent1, cent2, l;
vector<vector<int>> g;
int cnt[100005];

void dfs(int u, int prev) {

	cnt[u] = 1;

	//cout << "cnt[" << u + 1 << "] = " << cnt[u] << "\n";

	for(int i = 0; i < g[u].size(); i++) {
		if(g[u][i] == prev) continue;
		dfs(g[u][i], u);
		cnt[u] += cnt[g[u][i]];
	}
}

void findCent(int u) {

	for(int i = 0; i < g[u].size(); i++) {
		if(2 * cnt[g[u][i]] <= n) continue;
		cent1 = u;
		findCent(g[u][i]);
	}

	if(2 * cnt[cent1] != n) cent1 = 0;
	cent2 = u;
}

void leaf(int u, int prev) {

	if(g[u].size() == 1) {
		l = u;
		return;
	}

	for(int i = 0; i < g[u].size(); i++) {
		if(g[u][i] == prev || g[u][i] == cent1) continue;
		leaf(g[u][i], u);
	}
}

int main() {

	//ios_base::sync_with_stdio(0);
	//cin.tie(0); 
	//cout.tie(0);

	cin >> t;
	while(t--) {

		cent1 = -1, cent2 = -1, l = -1;

		cin >> n;

		g.assign(n, {});

		for(int i = 0; i < n - 1; i++) {
			cin >> x >> y; x--; y--;
			g[y].push_back(x);
			g[x].push_back(y);
		}

		// for each node count the number of nodes in its subtree
		dfs(0, -1);
		// find the centroid using this information
		findCent(0);

		if(cent1 >= 0 && cent2 >= 0) {
			// take leaf from cent1
			// add it to cent2
			leaf(cent2, -1);

			cout << l + 1 << " " << g[l][0] + 1 << "\n";
			cout << l + 1 << " " << cent1 + 1 << "\n";
		} else {
			// remove edge and add it back
			cout << "1 " << g[0][0] + 1 << "\n";
			cout << "1 " << g[0][0] + 1 << "\n";
		}
	}

	return 0;
}