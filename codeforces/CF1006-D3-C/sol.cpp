#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n, a, b;
ull s1, s3, maxS1;

int main() {

	scanf("%d", &n);
	int d[n];
	for(int i = 0; i < n; i++) { scanf("%d", &d[i]); }

	b = n - 1;
	s1 = d[a];
	s3 = d[b];
	while(a != b) {
		if(s1 == s3) {
			maxS1 = s1;
			s1 += d[++a];
		} else if(s1 > s3) {
			s3 += d[--b];
		} else {
			s1 += d[++a];
		}
	}

	printf("%llu\n", maxS1);

	return 0;
}