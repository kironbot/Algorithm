#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vc = vector<char>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

const ll MOD = 1000000007;
ll inv[10000100];
ll FactorialInv[10000100];
ll Factorial[10000100];
ll beki(ll a, ll b){
    a %= MOD;
    if(b == 0){
        return 1;
    }
    ll ans = beki(a, b / 2);
    ans = ans * ans % MOD;
    if(b % 2 == 1){
        ans = ans * a % MOD;
    }
    return ans;
}
void init_combination(){
    const int MAX = 10000002;
    Factorial[0] = 1;
    inv[0] = 1;
    for(int i = 1; i <= MAX; i++){
        Factorial[i] = Factorial[i - 1] * i % MOD;
    }
    FactorialInv[MAX] = beki(Factorial[MAX], MOD - 2);
    for(ll i = MAX - 1; i >= 0; i--) {
        FactorialInv[i] = FactorialInv[i+1] * (i+1) % MOD;
    }
    for(int i = 1; i <= MAX; i++) {
        inv[i] = FactorialInv[i] * Factorial[i-1] % MOD;
    }
}
ll combination(ll a, ll b){
    if((a == b) || (b == 0)){
        return 1;
    }
    if(a < b) return 0;
    ll ret = 1;
    for(ll i = 0; i < b; i++) {
        ret *= (a - i);
        ret %= MOD;
        ret *= beki(i + 1, MOD - 2);
        ret %= MOD;
    }
    return ret;
}


int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    init_combination();

    ll ans = beki(2, n) - 1 - combination(n, a) - combination(n, b);
    ans += 3 * MOD;
    ans %= MOD;
    cout << ans << endl;
}
