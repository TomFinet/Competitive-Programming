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

int k, n;

int main() {

	cin >> k;

	if(k % 7 == 0) {
		k /= 7;
	}
	
	if(k % 2 == 0 || k % 5 == 0) {
		cout << -1 << "\n";
	} else {
		n = 1;
		for(int i = 1 % k; ; i = (i * 10 + 1) % k) {
			if(i == 0) {
				cout << n << "\n"; 
				break;
			}
			n++;
		}
	}

	return 0;
}