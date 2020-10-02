#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define sint(a) scanf("%d", &a)
#define slong(a) scanf("%lld", &a);
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

int t, x, y, n;

int expo(int a, unsigned int b, int n) {
	int res = 1;
	while(b > 0) {
		if(b & 1) {
			res = (res * a) % n;
		}
		a = (a * a) % n;
		b >>= 1;
	}
	return res;
}

int main() {

	scanf("%d", &t);
	while(t--) {
		scanf("%d %d %d", &x, &y, &n);
		printf("%d\n", expo(x, y, n));
	}
	
	return 0;
}