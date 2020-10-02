#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define mem(a, b) memset(a, b, sizeof(a))
#define iter(it, l) for(auto it = l.begin(); it != l.end(); it++)
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
int a[100005], b[100005];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	while(t--) {

		cin >> n;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			b[i] = a[i];
		}

		sort(b, b + n);

		int min = b[0];
		
		bool impossible = false;

		for(int i = 0; i < n; i++) {
			if(b[i] != a[i]) { // a[i] is out of position
				if(a[i] % min != 0) { 
					impossible = true;
					break;
				}
			}
		}

		if(impossible) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
		}

	}

	return 0;

}