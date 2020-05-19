#include <bits/stdc++.h>

using namespace std;

int main() {

	ofstream myfile;
  	myfile.open ("ins.in");
  
	int t = 1000;
	int n = 5;
	myfile << t << "\n";
	for(int i = 0; i < t; i++) {
		myfile << n << "\n";
		for(int i = 0; i < n; i++) {
			int s = (rand() % 10) + 1;
			myfile << s << " ";
  
		}
		myfile << "\n";
	}

	myfile.close();

	return 0;
}