// 素数判定
//
// 計算量：O(√N)
//

#include <bits/stdc++.h>
using namespace std;

bool is_prime(long long n) {
    if (n <= 1) return false;
    for (long long p = 2; p <= n / p; p++) {
        if (n % p == 0) return false;
    }
    return true;
}

int main() {
    long long n;
    cin >> n;
    if (is_prime(n)) cout << "YES" << endl;
    else cout << "NO" << endl;
}
