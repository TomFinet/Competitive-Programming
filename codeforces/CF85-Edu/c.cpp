#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define mem(a, b) memset(a, b, sizeof(a))

const int MOD = 1000000007;
const int MAX = (int) 1e9;
const double PI = 3.141592653589793238462643383279502884;

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
ll a[300000], b[300000];

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0); 

	cin >> t;
	while(t--) {

		cin >> n;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			cin >> b[i];
		}

		// if a monster dies last its explosion damage will be wasted.
		// so shoot the monster who receives the least explosion damage first.

		int start = 0;
		ll minDmg = (ll) 1e13;
		for(int i = 0; i < n; i++) {
			int p = i == 0 ? n - 1 : i - 1;
			if(min(a[i], b[p]) < minDmg) {
				minDmg = min(a[i], b[p]);
				start = i;
			}
		}
		
		ll shots = 0;
		for(int i = 0; i < n; i++) {
			if(i == start) {
				shots += a[i];
			} else {
				int p = i == 0 ? n - 1 : i - 1;
				shots += max(a[i] - b[p], 0);
			}
		}

		cout << shots << "\n";
	}

	return 0;
}