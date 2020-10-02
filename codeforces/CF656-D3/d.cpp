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
string s;
unordered_map<char, int> l1, l2;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> t;
	while(t--) {

		cin >> n >> s;

		int ans = 0;
		char c = 'a';
		int l = 0, r = n;

		while(l < r) {

			for(auto &e : l1) e.second = 0;
			for(auto &e : l2) e.second = 0;

			if(l + 1 == r) {
				ans = s[l] != c ? ans + 1 : ans;
				break;
			}

			for(int i = l; i < r; i++) {
				if(2 * i < l + r) l1[s[i]]++;
				else if(2 * i >= l + r) l2[s[i]]++;
			}

			ans += (r - l) / 2 - max(l1[c], l2[c]);

			if(l1[c] < l2[c]) { r = (r + l) / 2; }
			else if(l1[c] > l2[c]) { l = (r + l) / 2; }
			else {
				char c1 = c + 1;
				while(1) {
					if(l1[c1] < l2[c1]) { l = (r + l) / 2; break; }
					if(l1[c1] > l2[c1]) { r = (r + l) / 2; break; }
					if(c1 == 'z' + 1) { l = (r + l) / 2; break; }
					c1++;
				}
			}

			c++;
		}

		cout << ans << "\n";

	}

	return 0;
}