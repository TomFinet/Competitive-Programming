#include <bits/stdc++.h>

typedef unsigned long long int ulli;
typedef unsigned int ui;

using namespace std;

ulli choose2(ulli n) {
    return n * (n - 1) / 2;
}

int main() {

    ulli n, m;
    cin >> n >> m;

    // start with min spread
    ulli minSpread = n / m;
    ulli remain = n % m;
    
    ulli minFriends = choose2(minSpread) * (m - remain) + 
        choose2(minSpread + 1) * remain;

    // max now
    ulli maxFriends = choose2(n - m + 1);
    
    cout << minFriends << " " << maxFriends;

    return 0;
}
