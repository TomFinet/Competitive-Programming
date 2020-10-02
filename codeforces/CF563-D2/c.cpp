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

int n;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	int c = 1;
	int colors[n] = {0};
	bool prime[n + 5];

	memset(prime, true, sizeof(prime));

	for(int i = 2; i <= n; i++) {
		if(prime[i]) {
			for(int j = i; j <= n; j += i) {
				prime[j] = false;
				if(colors[j - 1] == 0) colors[j - 1] = c;
			}
			prime[i] = true;
			c++;
		}
	}

	for(int i = 1; i <= n - 1; i++) {
		cout << colors[i] << " ";
	}

	return 0;
}