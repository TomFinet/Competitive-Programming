#include <bits/stdc++.h>

using namespace std;


int main() {

    int n, m, d; 
    scanf("%d %d %d", &n, &m, &d);

    vector<int> e;

    for(int i = 0; i < n; i++) {
        int a;
        for(int j = 0; j < m; j++) {
            scanf("%d", &a);
            e.push_back(a);  
        }
    }

    sort(e.begin(), e.end()); 
 
    int med = e[(m * n) / 2];
 
    int res = 0;
    for(int i = 0; i < m * n; i++) {
        int diff = abs(e[i] - med);
        if(diff % d != 0) {
            printf("-1");
            return 0;
        }
        res += diff / d;
    }

    printf("%d", res);

    return 0;
}
