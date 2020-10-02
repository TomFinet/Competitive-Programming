#include <bits/stdc++.h>
 
using namespace std;

inline int toDigit(char c) { return c - '0'; }

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); 

	long long a;
  	string bs;
  	int b = 0;

  	cin >> a >> bs;
  		
  	int p = 1;
  	for(int i = bs.length() - 1; i >= 0; i--) {
  		if(bs[i] == '.') { continue; }
  		b += p * toDigit(bs[i]);
  		p *= 10;
  	}

  	long long res = a * b / 100;
  	cout << res << "\n";
 
	return 0;
}