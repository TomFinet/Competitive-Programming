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

int t, n;
ll p, a;
bool yes;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);


	// if in boxes are in non-increasing order then it is NO

	cin >> t;
	while(t--) {

		cin >> n;
		cin >> p;
		
		yes = false;
		for(int i = 1; i < n; i++) {
			cin >> a;
			if(p <= a) yes = true;
			p = a;
		}

		if(yes) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}