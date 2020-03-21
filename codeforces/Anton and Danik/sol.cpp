#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, a = 0, d = 0;
    cin >> n;
    
    char c;
    for(int i = 0; i < n; i++) {
        cin >> c;
        if(c == 'A') {
            a++;
        } else {
            d++;
        }
    }
    
    
    string out;
    if(a > d) {
        out = "Anton";
    } else if(a < d) {
        out = "Danik";
    } else {
        out = "Friendship";
    }

    cout << out;

    return 0;
}
