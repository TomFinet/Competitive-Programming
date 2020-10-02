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

template<typename T>
T abs(T a, T b) {
	return a > b ? a - b : b - a;
}


int toDigit(char c) { return c - '0'; }

int n, m, bookA, bookB, ans;
ll a[200000], b[200000], k, sumA, sumB;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0); 

	cin >> n >> m >> k;

	for(int i = 0; i < n; i++) { cin >> a[i]; }
	for(int i = 0; i < m; i++) { cin >> b[i]; }
	
	for(int i = 0; i < n && sumA + a[i] <= k; i++) {
		sumA += a[i];
		bookA++;
	}

	for(int i = bookA; i >= 0; i--) { // num books from stack A
		// fit as many books from b as possible
		while(sumA + sumB + b[bookB] <= k && bookB < m) {
			sumB += b[bookB];
			bookB++;
		}

		ans = max(ans, i + bookB);
		sumA -= a[i - 1];

	}

	cout << ans << "\n";

	return 0;
}