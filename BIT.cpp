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

// BIT
// verify: https://judge.yosupo.jp/problem/static_range_sum

// 計算量はすべてO(logN)
// bit.add(i, val) a[i] += val
// bit.sum(l, r) [l, r) の合計
// bit.lower_bound(w) a[0] + ... + a[r] >= w となる最小のr
template <typename T>
class BIT {
    public:
    int N;
    vector<T> dat;

    public:
        BIT(int N) : N(N) { dat.assign(N, 0); }

    void add(int k, T val) {
        for (int x = k; x < N; x |= x + 1) {
            dat[x] += val;
        }
    }

    // [0, k)
    T sum(int k) {
        if (k >= N) k = N - 1;
        T ret = 0;
        for (int x = k - 1; x >= 0; x = (x & (x + 1)) - 1) {
            ret += dat[x];
        }
        return ret;
    }

    // [l, r)
    T sum(int l, int r) { return sum(r) - sum(l); }

    T get(int k) {
        assert(0 <= k && k < N);
        return sum(k + 1) - sum(k);
    }

    // a[0] + a[1] + ... + a[r] >= w なる最小のr
    int lower_bound(int w) {
        if (w <= 0) return -1;
        int x = 0;
        int k = 1;
        while (k * 2 <= N) k *= 2;
        for (; k > 0; k /= 2) {
            if (x + k <= N && dat[x + k - 1] < w) {
                w -= dat[x + k - 1];
                x += k;
            }
        }
        return x;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll N, Q; cin >> N >> Q;
    BIT<ll> bit(N+1);
    rep(i, N) {
      ll a; cin >> a;
      bit.add(i, a);
    }

    rep(i,Q) {
      ll l, r;
      cin >> l >> r;
      cout << bit.sum(l, r) << endl;
    }
}
