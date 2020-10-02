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
T inline max(T x, U y) {
    return x > y ? x : y;
}

template <typename T, typename U>
T inline min(T x, U y) {
    return x < y ? x : y;
}

template<typename T>
void inline debug(string msg, T t) {
	cout << msg << ": " << t << "\n";
}

int inline toDigit(char c) { return c - '0'; }

int t, n, good;
string a;
int p[10005];

int main() {

	sint(t);
	while(t--) {
		unordered_map<int, int> count;

		sint(n);
		getline(cin, a);

		p[0] = a[0];
		for(int i = 1; i < n; i++) {
			p[i] = p[i - 1] + a[i];
		}

		good = 0;

		for(int i = 0; i < n; i++) {
			int x = p[i] - i;
			unordered_map<int, int>::const_iterator got = count.find(x);
			if(got == count.end()) {
				count.emplace(x, 0);
			}
			good += count[x];
			count[x]++;
		}

		printf("%d\n", good);

	}

	return 0;
}