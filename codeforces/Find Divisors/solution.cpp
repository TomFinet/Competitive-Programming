#include <iostream>

using namespace std;

int main() {

	short l, r, k;
	cin >> l;
	cin >> r;
	cin >> k;

	if(k > r) {
		cout << 0;
	} else {

		short output = 0;

		for(; l <= r; l++) {
			if(l % k == 0) output++;
		}

		cout << output;
	}

	return 0;
}