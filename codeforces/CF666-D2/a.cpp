#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define mem(a, b) memset(a, b, sizeof(a))
#define MOD 1000000007
#define MAX (int) 1e9
#define PI 3.141592653589793238462643383279502884

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

int toDigit(char c) { return c - '0'; }

int t, n;
string s[1000];

int main() {

	cin >> t;
	while(t--) {

		unordered_map<char, int> l;
		cin >> n;
		bool possible = true;

		for(int i = 0; i < n; i++) {
			cin >> s[i];
			int m = s[i].length();
			for(int j = 0; j < m; j++) {
				unordered_map<char, int>::const_iterator got = l.find(s[i][j]);
				if(got != l.end()) {
					l[s[i][j]]++;
				} else {
					l.emplace(s[i][j], 1);
				}
			}
		}

		for(auto& it: l) {
		    if(it.second % n != 0) {
		    	possible = false;
		    }
		}

		if(possible) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	
	return 0;
}