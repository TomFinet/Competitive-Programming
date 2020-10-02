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

int t, n, a[105], ans[105];
bool l[105];
vector<int> unlocked;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> t;
	while(t--) {

		unlocked.clear();

		cin >> n;

		for(int i = 0; i < n; i++) cin >> a[i];
		for(int i = 0; i < n; i++) cin >> l[i];

		// find the largest unlocked position and place the smallest unlocked value in it

		for(int i = 0; i < n; i++) {
			if(!l[i]) unlocked.push_back(a[i]);
		}

		sort(unlocked.begin(), unlocked.end());

		int u = unlocked.size() - 1;
		for(int i = 0; i < n; i++) {
			if(l[i]) cout << a[i] << " ";
			else cout << unlocked[u--] << " ";
		}
		cout << "\n";
	}

	return 0;
}
