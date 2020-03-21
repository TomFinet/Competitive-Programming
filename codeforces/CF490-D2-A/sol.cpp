#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n, j;
    scanf("%d", &n);
   	vector<int> t1, t2, t3;
    for(int i = 1; i <= n; i++) {
    	scanf("%d", &j);
    	if(j == 1) {
    		t1.push_back(i);
    	} else if(j == 2) {
    		t2.push_back(i);
    	} else {
    		t3.push_back(i);
    	}
    }
 
    int w = min(t1.size(), min(t2.size(), t3.size()));
    printf("%d\n", w);
    for(int i = 0; i < w; i++) {
    	printf("%d %d %d\n", t1[i], t2[i], t3[i]);
    }

    return 0;
}

int min(int &a, int &b) {
    if(b >= a) {
        return b;
    }
    return a;
    
}
