#include <bits/stdc++.h>

using namespace std;

int main() {

	srand(time(NULL));

	ofstream in;
	in.open("in.txt");
	int n = 1000;
	
	in << n << "\n";
	for(int i = 0; i < n; i++) {
		in << rand() * -1 << " ";
	}

	in.close();

	return 0;
}