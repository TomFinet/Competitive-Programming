#include <bits/stdc++.h>

int main() {
    
    int n, h;    
    scanf("%d %d", &n, &h);

    int a; 
    int width = 0;

    for(int i = 0; i < n; i++) {
        scanf("%d", &a);
        if(a > h) {
            width++;
        }
        width++;
    }

    printf("%d", width);

    return 0;
}
