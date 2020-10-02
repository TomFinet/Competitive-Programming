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

const int ub = 28123;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	ll ans = 1;
	ll fs[ub + 5] = {1}; // every number has factor 1
	bool prime[ub + 5] = {true};
	for(int i = 2; i < ub; i++) {
		if(prime[i]) {
			for(int j = i; j < ub; j += i) {
				fs[i] += j;
				prime[j] = false;
			}
		}
	}

	return 0;
}
