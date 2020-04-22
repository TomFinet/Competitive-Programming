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

int t, n, q, l, r, yes;
bool y;

int main() {

	scanf("%d", &t);
	for(int ti = 1; ti <= t; ti++) {

		scanf("%d %d", &n, &q);
		string blocks;
		cin >> blocks;

		yes = 0;
		unordered_map<char, int> cnt;
		for(int i = 0; i < q; i++) {
			scanf("%d %d", &l, &r);

			for(int b = l - 1; b < r; b++) {
				cnt[blocks[b]]++;
			}

			y = true;
			for(auto iter = cnt.begin(); iter != cnt.end(); iter++) {
				if(iter->second % 2 == 1) {
					y = false;
					break;
				}
			}

			if(y) {
				yes++;
			}

		}

		printf("Case #%d: %d", ti, yes);
	}

	return 0;
}