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

int t, n, m;


int dfs(int start, int prev, vector<int> (&adj)[100000]) {
	int numNodes = 1;

	if(adj[start - 1].size() > 1) { // is not leaf
		for(int i = 0; i < adj[start - 1].size(); i++) {
			if(adj[start - 1][i] != prev) {
				// tree so no need to check for loops
				numNodes += dfs(adj[start - 1][i], start, adj);
			}
		}
	}

	return numNodes;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	while(t--) {

		cin >> n;
		vector<int> adj[100000];
		vector<pair<int, int>> edges;
		vector<int> edgeUses;

		for(int i = 1; i < n; i++) {
			int a, b;
			cin >> a >> b;
			edges.push_back({a, b});
			adj[a - 1].push_back(b);
			adj[b - 1].push_back(a);
		}

		cin >> m;
		int k[m];
		for(int i = 0; i < m; i++) {
			cin >> k[i];
		}
		sort(k, k + m);

		// for each edge count number of nodes on right
		for(int i = 0; i < n - 1; i++) {
			int nodesInSubtree = dfs(edges[i].first, edges[i].second, adj);
			edgeUses.push_back(nodesInSubtree * (n - nodesInSubtree));
		}

		sort(edgeUses.begin(), edgeUses.end());

		int diff = n - m - 1;
		ll ans = 0;

		// if diff is negative there are more prime factors than edges
		if(diff < 0) {
			for(int i = 0; i < n - 2; i++) {
				ans = (ans + edgeUses[i] * k[i]) % MOD;
			}

			ll prod = 1;
			for(int i = n - 2; i < m; i++) {
				prod = (prod * k[i]) % MOD;
			}

			ans = (ans + edgeUses[n - 2] * prod) % MOD;
		} else if(diff == 0) { // if diff is 0 there are the same
			for(int i = 0; i < n - 1; i++) {
				ans = (ans + edgeUses[i] * k[i]) % MOD;
			}
		} else { // if diff is positive there are less prime factors than edges
			for(int i = 0; i < diff; i++) { // allocate the weights of 1
				ans = (ans + edgeUses[i]) % MOD;
			}

			for(int i = 0; i < n - diff - 1; i++) {
				ans = (ans + edgeUses[i + diff] * k[i]) % MOD;
			}
		}
		
		cout << ans << "\n";

	}

	return 0;

}