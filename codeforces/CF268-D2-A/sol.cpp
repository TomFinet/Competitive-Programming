#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n, count = 0;
    cin >> n;
    
    int h[n], g[n];
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        h[i] = a;
        g[i] = b;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(h[i] == g[j]) {
                count++;
            } 
        }
    }
    
    cout << count;
    
    return 0;
}
