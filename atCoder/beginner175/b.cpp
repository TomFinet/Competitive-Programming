#include <bits/stdc++.h>

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

int toDigit(char c) { return c - '0'; }

int n, l[100], ans;

int main() {

	cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> l[i];
	}

	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			for(int k = j + 1; k < n; k++) {
				if(l[i] != l[j] && l[i] != l[k] && l[j] != l[k]) {
					if(l[i] + l[j] > l[k] && l[i] + l[k] > l[j] && l[j] + l[k] > l[i]) {
						ans++;
					}
				}
			}
		}
	}

	cout << ans << "\n";

	return 0;
}