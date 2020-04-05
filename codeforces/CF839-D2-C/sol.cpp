#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n, u, v;
vector<vector<int>> adjList;

double calcExp(int currNode, int prevNode) {
	vi children = adjList[currNode - 1];
	int len = children.size();

	// currNode is a leaf
	if(len == 1 && children[0] == prevNode) {
		return 0;
	}

	double exp = 0.0;
	int unvisitedChildren = len;
	for(int i = 0; i < len; i++) {
		if(children[i] != prevNode) {
			exp += 1.0 + calcExp(children[i], currNode);
		} else {
			unvisitedChildren--;
		}
	}

	return exp / ((double) unvisitedChildren);
}

int main() {

	scanf("%d", &n);

	if(n == 1) {
		printf("0.000000\n");
	} else {

		adjList.resize(n);

		for(int i = 0; i < n - 1; i++) {
			scanf("%d %d", &u, &v);
			adjList[u - 1].push_back(v);
			adjList[v - 1].push_back(u);
		}

		// implement a dfs
		double exp = calcExp(1, 1);
		printf("%.6f\n", exp);
	}

	return 0;
}