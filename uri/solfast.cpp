#include <bits/stdc++.h>

using namespace std;

#define sint(a) scanf("%d", &a)

int b[20];
int n, t, test;
unordered_set<int32_t> visitedStates; // keeps track of which states we have already seen, to avoid computing them again.
unordered_set<int32_t> currStates;

/**
 * Given 6 * 4-bit integers representing a state, translates it to a 32-bit integer key.
 */
int32_t stateToKey(const array<int, 6> &state) {
	int32_t key = 0;
	for(auto s : state) {
    	key <<= 4;
    	key += s;
  	}

	return key;
}

/**
 * Translates a 32-bit integer state key to 6 integers representing a state.
 */
array<int, 6> keyToState(int32_t key) {
	array<int, 6> state;
	for(int i = 5; i >= 0; i--) {
		state[i] = key & ~(~0 << 4);
		key >>= 4;
	}

	return state;
}

/**
 * Adds a state key to a set of states if it is unique.
 */
void addState(unordered_set<int32_t> &states, int32_t key) {
	array<int, 6> s = keyToState(key);

	array<array<int, 6>, 6> equivS {
		{{s[0], s[1], s[2], s[3], s[4], s[5]},
		{s[0], s[1], s[4], s[5], s[2], s[3]},
		{s[2], s[3], s[0], s[1], s[4], s[5]},
		{s[2], s[3], s[4], s[5], s[0], s[1]},
		{s[4], s[5], s[0], s[1], s[2], s[3]},
		{s[4], s[5], s[2], s[3], s[0], s[1]}}
	};

	for(int i = 0; i < 6; i++) {
		int32_t equivKey = stateToKey(equivS[i]);

		if(states.count(equivKey) == 1 || 
			visitedStates.count(equivKey) == 1) {
			return;
		}
	}

	states.insert(key);
}

/**
 * Given a state key, determines the available singers for replacement
 */
vector<int> availableSingers(int32_t key) {
	array<int, 6> s = keyToState(key);

	vector<int> a; // available singers for replacement
    vector<int> used = {s[0], s[2], s[4]};
    for(int i = 0; i < n; i++) {
    	bool free = true;
    	for(int j = 0; j < used.size(); j++) {
    		if(b[i] == used[j]) {
    			used.erase(used.begin() + j);
    			free = false;
    			break;
    		}
    	}

    	if(free) {
    		a.push_back(b[i]);
    	}
    }

    return a;
}


/**
 * Generates all unique transitions from state s1 at time t to s2 at time t + 1.
 */
unordered_set<int32_t> transition(int32_t key) {
	array<int, 6> s = keyToState(key);

	int time = min(min(s[1], s[3]), s[5]);
	s[1]--; s[3]--; s[4]--;

	vector<int> replaceIndex;
	for(int i = 1; i <= 5; i += 2) {
		if(s[i] == 0) {
			replaceIndex.push_back(i);
		}
	}

	unordered_set<int32_t> nextStates;
	if(replaceIndex.empty() || replaceIndex.size() == 3) {
		// no replacements needed.
		addState(nextStates, stateToKey(s));
	} else {

		// get a vector of available singers
		vector<int> a = availableSingers(key);

		// not enough singers for replacement
		if(a.size() < replaceIndex.size()) {
			unordered_set<int32_t> empty;
			return empty;
		}

		// handles single replacement
		array<int, 6> newS;
		if(replaceIndex.size() == 1) {
			for(int i = 0; i < a.size(); i++) {
				newS = s;
				newS[replaceIndex[0]] = a[i];
				newS[replaceIndex[0] - 1] = a[i];

				addState(nextStates, stateToKey(newS));
			}
		} else { // handles two replacements
			for(int i = 0; i < a.size(); i++) {
				for(int j = i + 1; j < a.size(); j++) {
					newS = s;
					newS[replaceIndex[0]] = a[i];
					newS[replaceIndex[0] - 1] = a[i];

					newS[replaceIndex[1]] = a[j];
					newS[replaceIndex[1] - 1] = a[j];

					addState(nextStates, stateToKey(newS));
				}
			}
		}
	}
	return nextStates;
}

/**
 * Returns true if state represents the song being over.
 * In other words all singers are out of breath.
 */
bool isSongOver(int32_t key) {
	array<int, 6> state = keyToState(key);
	if(state[1] == 0 && state[3] == 0 && state[5] == 0) {
		return true;
	}

	return false;
}

int main() {

	sint(n);
	for(int i = 0; i < n; i++) {
		sint(b[i]);
	}

	// generate initial states
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			for(int k = j + 1; k < n; k++) {
				array<int, 6> state = {b[i], b[i], b[j], b[j], b[k], b[k]};
				addState(currStates, stateToKey(state));
			}
		}
	}

	t = 0;
	bool singing = true;
	while(singing) {
		t++;
		unordered_set<int32_t> nextStates;
		for(auto currState : currStates) {
			for(auto nextState : transition(currState)) {
				if(isSongOver(nextState)) {
					singing = false;
				} else {
					addState(nextStates, nextState);
				}
			}
			addState(visitedStates, currState);
		}

		currStates = nextStates;
	}

	printf("%d\n", t);

	return 0;
}