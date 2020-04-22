#include <bits/stdc++.h>

using namespace std;

int main() {

	srand(time(NULL));

	ofstream in;
	in.open("in.txt");

	// code to generate test cases here.
	in << "200000\n";
	for(int i = 0; i < 200000; i++) {
		in << rand() << " ";
	}

	in << "\n";
	for(int i = 0; i < 200000; i++) {
		in << rand() << " ";
	}

	in.close();

	return 0;
}