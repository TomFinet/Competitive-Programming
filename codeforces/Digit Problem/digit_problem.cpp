#include <iostream>
#include <string>

#define ll long long

int main() {

		ll x;
		short k;

		std::cin >> x;
		std::cin >> k;

		// the largest number that can be created from k swaps is by modifying the rightmost k digits to 9s.
		// turn int to string
		// modify first k to 9's
		// return

		std::string s = std::to_string(x);

		for(int i = 0; i < k && k <= s_len; i++) {
			if (s[i] == '9') {
				k++;
				continue;
			}

			s[i] = '9';

		}

		std::cout << s;

	return 0;
}