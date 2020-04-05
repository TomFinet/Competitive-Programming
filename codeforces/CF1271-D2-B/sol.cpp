#include <bits/stdc++.h>

using namespace std;

int n, w, b, k;
vector<int> p;
string s;

int main() {

	scanf("%d", &n);
	cin >> s;

	for(int i = 0; i < n; i++) {
		// count w and b
		if(s[i] == 'W') {
			w++;
		} else {
			b++;
		}
	}

	if(w == n || b == n) {
		k = 0;
	} else if(w % 2 == 0) {
		// turn all to black
		for(int i = 0; i < n; i++) {
			if(s[i] == 'W') {
				p.push_back(i + 1);
				k++;
				if(s[i + 1] == 'W') {
					s[i + 1] = 'B';
				} else {
					s[i + 1] = 'W';
				}
			}
		}
	} else if(b % 2 == 0) {
		// turn all to white
		for(int i = 0; i < n; i++) {
			if(s[i] == 'B') {
				p.push_back(i + 1);
				k++;
				if(s[i + 1] == 'W') {
					s[i + 1] = 'B';
				} else {
					s[i + 1] = 'W';
				}
			}
		}
	} else {
		k = -1;
	}

	printf("%d\n", k);
	for(int i = 0; i < p.size(); i++) {
		printf("%d ", p[i]);
	}

	return 0;
}