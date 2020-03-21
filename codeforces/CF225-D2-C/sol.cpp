#include <bits/stdc++.h>

using namespace std;


int main() {

    int n, m, x, y, s;
    scanf("%d %d %d %d", &n, &m, &x, &y);

    int mods[m][2];
 
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &s);
            if(s == '.') {
                mods[i][0]++;
            } else {
                mods[i][1]++;
            }    
        }
    }

    minSum = iterate(x, y, 0, m);
   
    return 0;
}


int iterate(int &x, int &y, int startCol, int endCol, int changes, int &mods[][]) {
    
    for(int i = x; i <= y; i++) {
        for(int color = 0; color <= 1; color++) {
            for(int c = startCol; c < startCol + i; c++) {
                changes += mods[c][color];
            }
            iterate(x, y, startCol + i, endCol, changes, mods);
        }
    }

}
