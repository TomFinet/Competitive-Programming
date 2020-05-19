#include <bits/stdc++.h>

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

/**
 * Counts the number of occurences of @a in the array @arr.
 */
int countA(const array<int, combDim> &arr, int a) {
	int count = 0;
	for(auto const &e : arr) {
		if(e == a) {
			count++;
		}
	}

	return count;
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

	while(!states.empty()) {
		array<int, stateDim> state = states.top();
		states.pop();

		tElapsed = state[0]; // elpased time so far
		s1 = state[1]; // first singer
		r1 = state[2]; // breath remaining for first singer
		s2 = state[3]; // second singer
		r2 = state[4]; // breath remaining for second singer
		o1 = state[5]; // out of breath singer
		
		printf("%d %d %d %d %d %d\n", tElapsed, s1, r1, s2, r2, o1);

		// check if state represents end of song
		if(r1 == 0 && r2 == 0) {
			t = tElapsed;
			break;
		}

		for(auto &singer : singerCount) {
			int s = singer.first;
			
			// check that singer, s, is not out of breath or already singing
			array<int, 3> used = {s1, s2, o1};
			if(countA(used, s) >= singerCount[s]) {
				continue;
			}

			// s is available so create a new state with it and add to priority queue.
			int timeIncr = min(min(r1, r2), s);

			array<int, stateDim> newState;
			if(timeIncr == r1) {
				newState = {tElapsed + timeIncr, s2, r2 - timeIncr, s, s - timeIncr, s1};
			} else if(timeIncr == r2) {
				newState = {tElapsed + timeIncr, s1, r1 - timeIncr, s, s - timeIncr, s2};
			} else {
				newState = {tElapsed + timeIncr, s1, r1 - timeIncr, s2, r2 - timeIncr, s};
			}

			states.push(newState);
	    }
    }	

	printf("%d\n", t);

	return 0;
}
