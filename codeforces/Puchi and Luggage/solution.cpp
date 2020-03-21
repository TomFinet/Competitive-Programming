#include <bits/stdc++.h>

using namespace std;


int main() {

	int t, n;
	cin >> t;

	while(t--) {
		cin >> n;
        
		vector<int> w(n), w_sort(n);
		int temp;
		for(int i = 0; i < n; i++) {
			cin >> temp;
			w[i] = w_sort[i] = temp;
		}

		// sort the weight array.
		// for each element in the unsorted weight array
		// find it in the ortedd array and its index will be the number of smaller weights
		// remove it from the sorted array

		sort(w_sort.begin(), w_sort.end());
        vector<int>::iterator iter;
        for(int i = 0; i < n; i++) {
        	iter = lower_bound(w_sort.begin(), w_sort.end(), w[i]) // uses binary search
        	cout << iter - w_sort.begin() << " ";
        	w_sort.erase(iter);
        }

        cout << endl;

	}


	return 0;
}