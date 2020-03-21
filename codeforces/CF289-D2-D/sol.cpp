#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;


int main() {

    int n, k;
    scanf("%d %d", &n, &k);

    uint64_t res = 1;
    for(int i = 0; i < k - 1; i++) {
        res = (res * k) % MOD;
    }
    for(int i = 0; i < n - k; i++) {
        res = (res * (n - k)) % MOD;
    }

    printf("%lu", res);

    return 0;
}
