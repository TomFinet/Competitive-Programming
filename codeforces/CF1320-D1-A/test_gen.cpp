#include <bits/stdc++.h>

using namespace std;


int main() {

	ofstream out;
	out.open("ins.in");
	int n;
	cin >> n; 

	out << n << "\n";

	for(int i = 0; i < n; i++) {
		out << i + 200000 << " ";
	}
	out.close(); 

	return 0;
}