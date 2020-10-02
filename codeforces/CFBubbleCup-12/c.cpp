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

string a;
int l, b[100005];

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> l >> a;
	int n = a.length();
	if(n % l != 0 || n < l) {
		for(int i = 0; i < n; i += l) {
			cout << "1";
			for(int j = i + 1; j < i + l; j++) cout << "0";
		}

		return 0;
	}
	
	if(n == l) {
		a[n - 1]++;
		cout << a;
		return 0;
	}

	for(int i = 0; i < l; i++) b[i] = toDigit(a[i]);

	bool greater = false;
	for(int i = l; i < n; i += l) {

		for(int j = l - 1; j >= 0; j--) {
			int d = toDigit(a[i + j]);
			if(d == b[j] && i + l >= n - 1) {
				greater = true;
				break;
			}

			if(d <= b[j]) continue;
			
			if(d > b[j]) {
				greater = true;
				break;
			}
		}

		if(greater) break;
	}

	if(greater) {

		int carry = 0;
		for(int i = l - 1; i >= 0; i--) {
			if(b[i] == 9) {
				b[i] = carry;
				carry = 1;
			} else {
				b[i] += carry;
				carry = 0;
				break;
			}
		}

		int extra = 0;
		if(carry == 1) {
			b[0] = 1;
			for(int i = 1; i < l; i++) {
				b[i] = 0;
			}

			extra = l;
		}

		for(int i = 0; i < n + extra; i += l) {

			for(int j = 0; j < l - 1; j++) cout << b[j];
			if(extra == 0) cout << b[l - 1] + 1;
			else cout << b[l - 1];
		}
	} else {
		for(int i = 0; i < n; i += l) {
			for(int j = 0; j < l; j++) cout << b[j];
		}
	}

	return 0;
}
