#include <iostream>
#include <cmath>

using namespace std;

#define ll long long

int main() {

	int n; // length of int array
	cin >> n;

	int k;
	ll int ans = 1;
	for(int i = 0; i < n; i++) {
		cin >> k;
		ans = (ans * k) % (1000000007);
	}

	cout << ans;

	return 0;
}