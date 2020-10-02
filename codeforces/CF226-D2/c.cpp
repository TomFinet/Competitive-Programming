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

const int maxX = 10000000;

int n, x, m, l, r, cnt[maxX + 5], pre[maxX + 5];
bool p[10000005];

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	memset(p, true, sizeof(p));

	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> x;
		cnt[x]++; // count occurences of each number in x
	}

	for(int i = 2; i <= maxX; i++) {
		pre[i] = pre[i - 1];
		if(p[i]) {
			for(int j = i; j <= maxX; j += i) {
				pre[i] += cnt[j];
				p[j] = false;
			}
		}
	}

	cin >> m;
	for(int i = 0; i < m; i++) {
		cin >> l >> r;
		l = min(l, maxX);
		r = min(r, maxX);
		cout << pre[r] - pre[l - 1] << "\n";
	}

	return 0;
}