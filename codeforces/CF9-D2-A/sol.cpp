#include <bits/stdc++.h>

using namespace std;

int main() {

    int y, w;
    scanf("%d %d", &y, &w);
    
    int max;
    if(y >=w ) {
        max = y;
    } else {
        max = w;
    }
    
    string probs[6] = {"1/6", "1/3", "1/2", "2/3", "5/6", "1/1"};
    int top = 6 - max;
    cout << probs[top];

    return 0;
}
