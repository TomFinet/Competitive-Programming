#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

template <typename T, typename U>
T max(T x, U y) {
    return x > y ? x : y;
}

template <typename T, typename U>
T min(T x, U y) {
    return x < y ? x : y;
}

int t, n, a, b;
string alpha = "abcdefghijklmnopqrstuvwxyz";

int main() {

	scanf("%d", &t);
	while(t--) {

		
		string out;
		scanf("%d %d %d", &n, &a, &b);
		int j = 0;
		for(int i = 0; i < n; i++) {
			if(j >= b) {
				j = 0;
			}
			out.append(1, alpha[j++]);
		}

		cout << out << "\n";

	}

	return 0;
}