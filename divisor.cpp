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

/*  約数列挙（エラトステネスの篩）
    入力: N
    出力: cnt[i]: {1..N}の約数としてのiの出現回数
    計算量: O(NlogN)
*/

int main() {
    ll N;
    cin >> N;
    vll cnt(N+1, 0);
    for(ll i = 1; i <= N; i++) {
        for(ll j = i; j <= N; j += i) {
            cnt[j]++;
        }
    }
}
