#include<bits/stdc++.h>

using namespace std;

#define sint(a) scanf("%d", &a)
	
int n, s1, r1, s2, r2, o1, t, tElapsed;
int b[20];
unordered_map<int, int> singerCount;
unordered_set<int16_t> visited; // keeps track of visited states

const int stateDim = 6;
const int combDim = 3;

struct compareFirst {
    bool operator()(const std::array<int, stateDim> &a, const std::array<int, stateDim> &b) {
        return a[0] > b[0];
    }
};

priority_queue<array<int, stateDim>, vector<array<int, stateDim>>, compareFirst> states; // prioritze states with smallest time elapsed.

/**
 * Given 4 * 4-bit integers representing a state, translates it to a 16-bit integer key.
 */
int16_t combToKey(const array<int, combDim> &comb) {
	int16_t key = 0;
	for(auto c : comb) {
    	key <<= 4;
    	key += c;
  	}

	return key;
}

int main() {


	sint(n);
	for(int i = 0; i < n; i++) {
		sint(b[i]);
		singerCount[b[i]]++;
	}

	// generate initial states
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			for(int k = j + 1; k < n; k++) {
				array<int, combDim> comb = {b[i], b[j], b[k]};

				printf("%d %d %d\n", i, j, k);

				sort(comb.begin(), comb.end());

				if(visited.count(combToKey(comb)) == 0) { 
					o1 = tElapsed = comb[0]; s1 = comb[1]; s2 = comb[2]; 
					array<int, stateDim> state = {
						tElapsed, 
						s1, s1 - tElapsed,
						s2, s2 - tElapsed,
						o1
					};
					states.push(state);
				}
				visited.insert(combToKey(comb));
			}
		}
	}


	return 0;
}

