#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int strips = 4;
    int a[strips]; 
    
    for(int i = 0; i < strips; i++) {
        scanf("%d", &a[i]);
    }

    string s;
    cin >> s;
    
    int cals = 0;
    for(int i = 0; i < s.length(); i++) {
        int si = s[i] - '0';
        cals += a[si - 1];    
    }
    
    printf("%d", cals);


    return 0;
}
