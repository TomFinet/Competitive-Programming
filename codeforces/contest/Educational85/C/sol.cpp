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

int t, n, lastKilled, firstKilled;
ll minDeathDamage, minShots;

int main() {

	scanf("%d", &t);
	while(t--) {
		minShots = 0;
		scanf("%d", &n);

		ll m[n][2];
		for(int i = 0; i < n; i++) {
			scanf("%lld %lld", &m[i][0], &m[i][1]);
		}

		minDeathDamage = 100000000000000;
		lastKilled = 0;
		for(int i = 0; i < n; i++) {
			int after = i + 1;
			if(i == n - 1) {
				after = 0;
			}
			ll deathDamage = m[after][0] - max(0, m[after][0] - m[i][1]);
			if(deathDamage < minDeathDamage) {
				lastKilled = i;
				minDeathDamage = deathDamage;
			}
		}


		firstKilled = lastKilled + 1;
		if(lastKilled == n - 1) {
			firstKilled = 0;
		}

		for(int i = 0; i < n; i++) {
			if(i == firstKilled) {
				minShots += m[i][0];
			} else {
				int before = i - 1;
				if(i == 0) {
					before = n - 1;
				}
				minShots += max(0, m[i][0] - m[before][1]);
			}
		}
		
		printf("%lld\n", minShots);
	}


	return 0;
}