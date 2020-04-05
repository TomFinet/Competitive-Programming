#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> s;
vector<vector<int>>subsets;

void search(int k) {
	if(k == n) {
		subsets.push_back(s);
	} else {
		search(k+1);
		s.push_back(k);
		search(k+1);
		s.pop_back();
	}
}

int main() {

	scanf("%d", &n);
	search(0);
	
	for(int i = 0; i < subsets.size(); i++) {
		for(int j = 0; j < subsets[i].size(); j++) {
			cout << subsets[i][j] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}