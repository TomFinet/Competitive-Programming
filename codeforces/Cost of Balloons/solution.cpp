#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	int t;
	cin >> t;

	int green, purple, n, prob1, prob2;

	while(t-- > 0) {

		prob1 = prob2 = 0;

		cin >> green;
		cin >> purple;
		cin >> n;

		for(int i = 0; i < n; i++) {
			int hasFirst, hasSecond;
			cin >> hasFirst;
			cin >> hasSecond;
			
			if(hasFirst) prob1++;
			if(hasSecond) prob2++;

		}

		int cost1 = prob1 * green + prob2 * purple;
		int cost2 = prob1 * purple + prob2 * green;

		cout << min(cost1, cost2) << endl;

	}

	return 0;
}