#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <string>

bool is_prime(int& n) {
	for(int i = 2; i <= std::sqrt(n); i++) {
		if(n % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {

	std::ifstream infile("in.txt");
	std::string line;
	std::getline(infile, line);
    std::stringstream ss(line);
    int n;
    ss >> n;

	for(int i = 2; i <= n; i++) {
		if(is_prime(i)) {
			std::cout << i << " ";
		}
	}	

	infile.close();
	
	return 0;
}