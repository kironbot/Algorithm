#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vc = vector<char>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using stkll = vector<pll>;
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
#define rep(i, n) for (ll i = 0; i < (n); i++)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x << ": " << x << endl;
#else
    #define debug(x)
#endif

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    // 二分探索テンプレ（定義してない変数があるので、コンパイルできない注意）
    // [0, N) で条件を満たす最も小さいokを探す
    ll ng = -1;
    ll ok = N;
    while(ok - ng > 1) {
        ll mid = ng + (ok - ng) / 2;

        // midが条件を満たすかチェック
        if(f(mid) == true) ok = mid;
        else ng = mid;
    }
    // 答えはokに入る
    ll ans = ok;
}
