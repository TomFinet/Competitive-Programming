#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int k, r, i = 1;
    scanf("%d %d", &k, &r);
    
    for(; ; i++) {
        int ld = (i * k) % 10;
        if(ld == 0 || ld == r) {
            break;
        }
    }

    printf("%d", i);
    
    return 0;
}
