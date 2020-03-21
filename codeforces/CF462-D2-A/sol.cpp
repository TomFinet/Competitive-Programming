#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n;
    cin >> n;    
    int b[n][n];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            char c;
            cin >> c;
            if(c == 'o') {
                b[i][j] = 0;
            } else {
                b[i][j] = 1;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int s = 0;
            if(j > 0 && (b[i][j - 1] == 0)) {
                s++;
            }
            if(j < n - 1 && (b[i][j + 1] == 0)) {
                s++;
            }
            if(i > 0 && (b[i - 1][j] == 0)) {
                s++;
            }
            if(i < n - 1 && (b[i + 1][j] == 0)) {
                s++;
            }
            if(s % 2 == 1) {
                cout << "NO";
                return 0;
            }
        }
    }

    cout << "YES";

    return 0;
}
