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

int t, n, a, distinct, same;

int main() {

	scanf("%d", &t);
	while(t--) {
		same = 0;
		distinct = 0;
		unordered_map<int, int> found;

		scanf("%d", &n);

		for(int i = 0; i < n; i++) {
			scanf("%d", &a);
			found[a]++;
		}

		if(n == 1) {
			printf("0\n");
		} else {
			for(auto iter = found.begin(); iter != found.end(); iter++) {
				if(iter->second == 1) {
					distinct++;
				} else {
					if(same < iter->second) {
						if(same != 0) {
							distinct++;
						}
						same = iter->second;
					} else {
						distinct++; 
					}
				}
			}

			if(distinct == n || same == n) {
				printf("1\n");
			} else if(same > distinct) {
				printf("%d\n", min(distinct + 1, same - 1));
			} else {
				printf("%d\n", min(distinct, same));
			}
		}

	}

	return 0;
}