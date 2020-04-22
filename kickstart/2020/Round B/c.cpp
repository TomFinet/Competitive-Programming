#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define sint(a) scanf("%d", &a)
#define slong(a) scanf("%lld", &a);
#define mem(a, b) memset(a, b, sizeof(a))
#define iter(it, l) for(auto it = l.begin(); it != l.end(); it++)
#define MOD 1000000007
#define MAX (int) 1e9

template <typename T, typename U>
T max(T x, U y) {
    return x > y ? x : y;
}

template <typename T, typename U>
T min(T x, U y) {
    return x < y ? x : y;
}

int toDigit(char c) { return c - '0'; }

int t, n, cnt[4], s, tmp;
string prg;

void countChars(ll mult) {
	for(; s < prg.size(); s++) {
		if(isdigit(prg[s])) {
			tmp = s;
			s += 2;
			countChars((toDigit(prg[tmp]) * mult) % MAX);
		} else if(prg[s] == 'N') {
			cnt[0] = (cnt[0] + mult) % MAX;
		} else if(prg[s] == 'E') {
			cnt[1] = (cnt[1] + mult) % MAX;
		} else if(prg[s] == 'S') {
			cnt[2] = (cnt[2] + mult) % MAX;
		} else if(prg[s] == 'W') {
			cnt[3] = (cnt[3] + mult) % MAX;
		} else {
			return;
		}
	}
}

int main() {

	sint(t);
	for(int ti = 1; ti <= t; ti++) {
		s = 0;
		mem(cnt, 0);
		cin >> prg;

		countChars(1);

		int moveSouth = cnt[2] - cnt[0];
		int moveEast = cnt[1] - cnt[3];

		if(moveSouth < 0) {
			moveSouth = MAX + moveSouth + 1;
		} else {
			moveSouth++;
		}

		if(moveEast < 0) {
			moveEast = MAX + moveEast + 1;
		} else {
			moveEast++;
		}

		printf("Case #%d: %d %d\n", ti, moveEast, moveSouth);
	}

	return 0;
}
