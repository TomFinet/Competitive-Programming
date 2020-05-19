#include <bits/stdc++.h>

using namespace std;


int main() {

	string linecppl, linepy;
	ifstream cppl("out.txt");
	ifstream py("outpy.txt");
	if (cppl.is_open() && py.is_open()) {
		int l = 0;
		while (getline(cppl, linecppl) && getline(py, linepy)) {
			l++;
		  if(stoi(linecppl) != stoi(linepy)) {
		  	cout << "line: " << l << " " << "cpp: " << linecppl << " | py: " << linepy << "\n";
		  }
		}
		cppl.close();
		py.close();
	}

	return 0;
}