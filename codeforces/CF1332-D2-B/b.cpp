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

int t, n, m, a[1000]; // color of ith element
vector<int> p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31}; // first 11 primes

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> t;
	while(t--) {

		cin >> n;

		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}

		int c[n] = {0};

		int m = 0;
		for(int j = 0; j < 11; j++) {
			bool got = false;
			for(int i = 0; i < n; i++) {
				if(a[i] % p[j] == 0 && c[i] == 0) {
					c[i] = m + 1;
					got = true;
				}
			}

			if(got) {
				m++;
			}
		}

		cout << m << "\n";

		for(int i = 0; i < n; i++) {
			cout << c[i] << " ";
		}
		cout << "\n";
	}

	return 0;
}