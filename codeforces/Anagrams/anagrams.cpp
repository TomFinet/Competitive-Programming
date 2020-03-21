#include <iostream>
#include <string>


int countLonelyLetters(std::string a, std::string b) {
	int moves = 0;
	for (int i = 0; i < a.length(); i++) {
		bool bothHaveLetter = false;

		for (int j = 0; j < b.length(); j++) {
			
			if (a[i] == b[j]) {
				bothHaveLetter = true;
				b[j] = ' ';
				break;
			}
		}

		if (!bothHaveLetter) {
			// we need to remove a[i] from string a, so add 1 to number of moves.
			moves++;
		}
	}

	return moves;
}


int main() {

	int t;

	std::cin >> t;

	for (int i = 0; i < t; i++) {
		std::string a;
		std::string b;

		std::cin >> a;
		std::cin >> b;

		int moves = 0;

		moves += countLonelyLetters(a, b);
		moves += countLonelyLetters(b, a);	

		std::cout << moves << std::endl;
	}

	return 0;

}