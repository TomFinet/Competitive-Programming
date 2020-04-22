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

int t;
int a[9] = {0, 3, 6, 1, 4, 7, 2, 5, 8};

int main() {

	scanf("%d", &t);
	while(t--) {
		string board[9];
		for(int i = 0; i < 9; i++) {
			cin >> board[i];
		}

		for(int i = 0; i < 9; i++) {
			board[i][a[i]] = (board[i][a[i]] == '9' ? '1' : board[i][a[i]] + 1);
		}

		for(int i = 0; i < 9; i++) {
			for(int j = 0; j < 9; j++) {
				printf("%c", board[i][j]);
			}
			printf("\n");
		}

	}

	return 0;
}