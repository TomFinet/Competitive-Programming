#include <iostream>
#include <string>

using namespace std;


int main() {

	string s;
	cin >> s;

	short s_len = s.length();

	string output;

	for(int i = 0; i < s_len / 2; i++) {
		if(s[i] != s[s_len - i - 1]) {
			output = "NO";
			break;
		}
	}

	if(output.empty()) {
		output = "YES";
	}

	cout << output;

	return 0;
}