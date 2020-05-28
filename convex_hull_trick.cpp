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

// Convex Hull Trick
// verify: https://atcoder.jp/contests/dp/tasks/dp_z
// 直線 ax+b 追加 O(1)
// x における最小値取得 O(1)
struct ConvexHullTrick {
    struct Line {
        long long a, b;
        long long get(long long x) { return a * x + b; }
    };
    deque<Line> que;
    bool check(Line a, Line b, Line c) {
        return (b.b - c.b) * (b.a - a.a) <= (a.b - b.b) * (c.a - b.a);
    }
    void add(long long a, long long b) {
        Line l{a, b};
        while(que.size() > 1 && check(que[que.size() - 2], que.back(), l))
            que.pop_back();
        que.push_back(l);
    }
    long long query(long long x) {
        if(que.empty()) return INT64_MAX;
        while(que.size() > 1 && que[0].get(x) >= que[1].get(x))
            que.pop_front();
        return que[0].get(x);
    }
};

int main() {
    cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(20);

    ll N, C; cin >> N >> C;
    vll h(N);
    rep(i,N) cin >> h[i];

    vll dp(N, 0);
    ConvexHullTrick ch;
    ch.add(-2*h[0], dp[0] + h[0]*h[0]);
    for(ll i = 1; i < N; i++) {
        dp[i] = ch.query(h[i]) + h[i]*h[i] + C;
        ch.add(-2*h[i], dp[i] + h[i]*h[i]);
    }
    cout << dp[N-1] << endl;
}
