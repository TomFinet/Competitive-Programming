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
T& abs(T& a, T& b) {
	return a > b ? a - b : b - a;
}

inline int toDigit(char c) { return c - '0'; }

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0); 

	int n, m, x, y;
	cin >> n >> m >> x >> y;

	bool board[n][m];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			board[i][j] = false;
		}
	}

	// go to top
	for(int i = x; i >= 1; i--) {
		cout << i << " " << y << "\n";
		board[i - 1][y - 1] = true;
	}

	// go to left
	for(int j = y - 1; j >= 1; j--) {
		cout << 1 << " " << j << "\n";
		board[0][j - 1] = true;
	}

	// now at (1, 1)
	// traverse board row by row
	for(int i = 0; i < n; i++) {
		if(i % 2 == 0) {
			for(int j = 0; j < m; j++) {
				if(board[i][j] == true) {
					continue;
				}

				cout << i + 1 << " " << j + 1 << "\n";
			}
		} else {
			for(int j = m - 1; j >= 0; j--) {
				if(board[i][j] == true) {
					continue;
				}

				cout << i + 1 << " " << j + 1 << "\n";
			} 
		}
	}

	return 0;
}