#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

template <typename T, typename U>
T max(T x, U y) {
    return x > y ? x : y;
}

template <typename T, typename U>
T min(T x, U y) {
    return x < y ? x : y;
}

int n, i, j, ans;

int main() {

	scanf("%d", &n);

	unordered_set<int> seen;
	int a[n], b[n];

	for(int i = 0; i < n; i++) { scanf("%d", &a[i]); }
	for(int i = 0; i < n; i++) { scanf("%d", &b[i]); }

	i = 0; j = 0, ans = 0;
	while(i < n && j < n) {
		unordered_set<int>::const_iterator got = seen.find(a[i]);
		if(got != seen.end()) {  
			i++;
			continue;
		}

		if(a[i] != b[j]) {
			seen.emplace(b[j]);
			ans++;
		} else {
			i++;
		}
		
		j++;
	}

	printf("%d\n", ans);
	

	return 0;
}