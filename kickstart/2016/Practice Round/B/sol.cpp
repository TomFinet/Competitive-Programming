#include <bits/stdc++.h>

using namespace std;


int main() {

    int n, k, t;
    scanf("%d", &t);
    
    ofstream out;
    out.open("out.txt");

    for(int i = 1; i <= t; i++) {
        scanf("%d %d", &n, &k);
        int a[n], b[n], c[n], d[n];
        
        for(int h = 0; h < n; h++) { scanf("%d", &a[h]); }
        for(int h = 0; h < n; h++) { scanf("%d", &b[h]); }
        for(int h = 0; h < n; h++) { scanf("%d", &c[h]); }
        for(int h = 0; h < n; h++) { scanf("%d", &d[h]); }

        uint64_t res = 0;
        unordered_map<int, int> map;          

        for(int w = 0; w < n; w++) {
            for(int x = 0; x < n; x++) {
                map[a[w] ^ b[x]]++;
            }
        }

        unordered_map<int, int>::iterator iter;
        for(int y = 0; y < n; y++) {
            for(int z = 0; z < n; z++) {
                iter = map.find((c[y] ^ d[z]) ^ k);
                if(iter != map.end()) {
                    res += iter->second;
                }
            }
        }
        
        out << "Case #" << i << ": " << res << "\n";

    }    

    
    out.close();

    return 0;
}