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

int t, n, k;
string a, b;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	while(t--) {

		vector<int> p;

		int k = 0;

		cin >> n;
		cin >> a;
		cin >> b;

		for(int i = n - 1; i >= 0; i--) {
			if(a[i] != b[i]) { // last two bits are unequal
				if(a[0] == b[i]) { // a's first bit is equal to b's last bit
					k++;
					p.push_back(1);
					a[0] = a[0] == '1' ? '0' : '1';
				}

				k++;
				p.push_back(i + 1);

				for(int j = 0; j <= i; j++) {
					a[j] = a[j] == '1' ? '0' : '1'; // flip
				}

				for(int j = 0; j <= (i / 2); j++) { // reverse
					int tmp = a[j];
					a[j] = a[i - j];
					a[i - j] = tmp;
				}

			}
		}
		
		cout << k << " ";
		for(int i = 0; i < k; i++) {
			cout << p[i] << " ";
		}
		cout << "\n";



	}

	return 0;

}