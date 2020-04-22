#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, x, y, sameX, sameY, samePoint, ans;

int main() {

	scanf("%lld", &n);
	map<ll, ll> xMap, yMap;
	map<pair<ll, ll>, ll> xyMap;

	for(int i = 0; i < n; i++) {
		scanf("%lld %lld", &x, &y);
		sameX += xMap[x]++;
		sameY += yMap[y]++;
		samePoint += xyMap[make_pair(x, y)]++;
	}

	ans = sameX + sameY - samePoint;
	printf("%lld", ans);


	return 0;
}