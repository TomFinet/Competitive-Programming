#include <bits/stdc++.h>

using namespace std;


int main() {

    int a, b, s;
    scanf("%d %d %d", &a, &b, &s);
    
    int minS = abs(a) + abs(b);   

    if(minS > s || (s - minS) % 2 != 0) {
        printf("No");
    } else {
        printf("Yes");
    }
    return 0;
}
