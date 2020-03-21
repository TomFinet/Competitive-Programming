#include <iostream>
#include <fstream>
#include <string>


void reverse_string(std::string& sequence) {

	unsigned int len = sequence.length();

	for(int i = 0; i < len / 2; i++) {
		std::swap(sequence[i], sequence[len - 1 - i]);
	}
}

int main() {
        
	std::fstream infile;
	infile.open("in.txt", std::ios::in);
	if(infile.is_open()) {
		std::string sequence;
		while(getline(infile, sequence)) {
			reverse_string(sequence);
			std::cout << sequence << std::endl;
		}

		infile.close();
	}

	return 0;
}