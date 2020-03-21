#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

string w;

int main() {
    
    int t;
    cin >> t;

    ofstream out;
    out.open("out.txt");
    
    for(int i = 1; i <= t; i++) {
        uint64_t ans = 1;
        cin >> w;
        // count the number of distinct letters in each consecutive triple
        int ways;
        int len = w.length();
        
        if(len == 1) {
            out << "Case #" << i << ": " << ans << "\n";
            continue;
        }

        for(int i = 0; i < len; i++) {
            if(i == 0) {
                if(w[0] == w[1]) {
                    ways = 1;
                } else {
                    ways = 2;
                }
            } else if(i == len - 1) {
                if(w[i] == w[i - 1]) {
                    ways = 1;
                } else {
                    ways = 2;
                }
            } else {
                if(w[i - 1] != w[i] && w[i] != w[i + 1] && w[i - 1] != w[i + 1]) {
                    // three distinct
                    ways = 3;
                } else if(w[i - 1] == w[i] && w[i] == w[i + 1]) {
                    ways = 1;
                } else {
                    ways = 2;
                }
            }
            ans = (ans * ways) % MOD;
        }
        
        out << "Case #" << i << ": " << ans << "\n";
    } 

    return 0;
}
