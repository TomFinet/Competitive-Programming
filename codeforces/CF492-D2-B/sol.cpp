#include <bits/stdc++.h>

using namespace std;


int main() {

    int n, l;
    scanf("%d %d", &n, &l);
    
    vector<int> a;
    a.reserve(n);
    int tmp;
    for(int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        a.push_back(tmp);
    }

    sort(a.begin(), a.end());
    
    int maxD = 0;
    for(int i = 0; i < n - 1; i++) {
        maxD = max(maxD, a[i + 1] - a[i]);
    }
    
    double d = (double) (maxD) / 2.0;
    d = max(d,(double) a[0]);
    d = max(d, (double) (l - a[n - 1]));

    cout << fixed << setprecision(9) << d;

    return 0;
}
