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

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0); 

	ll n;
	string name;

	cin >> n;

	ll p = 26, bound = p;
	for(int i = 1; i <= 11; i++) {
		if(n <= bound) {
			n -= (bound - p + 1); // if n is 1 it refers to first name within range
			// determine each of the i characters of the name
			for(int c = i - 1; c >= 0; c--) {
				p /= 26;
				int l = n / p;
				name += 'a' + l;
				n -= l * p;
			}
			break;
		}

		p *= 26;
		bound = bound + p;
	}

	cout << name << "\n";

	return 0;
}