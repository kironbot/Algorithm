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

/*  経路復元 Dijkstra(G,s,dis,pre)

    verify: ABC168/D https://atcoder.jp/contests/abc168/tasks/abc168_d

    入力：グラフ G, 開始点 s, 距離を格納する dis, 最短経路の前の点を記録するpre
    計算量：O(|E|log|V|)
    副作用：dis, preが書き換えられる
*/
struct Edge {
    ll to;
    ll cost;
    Edge(ll to, ll cost) : to(to), cost(cost) {}
};
using Graph = vector<vector<Edge>>;
using P = pair<long, int>;
vll dis;
vector<int> pre;

void dijkstra(const Graph &G, int s, vector<long long> &dis, vector<int> &pre) {
    int N = G.size();
    dis.resize(N, INF);
    pre.resize(N, -1); // 初期化
    priority_queue<P, vector<P>, greater<P>> pq;
    dis[s] = 0;
    pq.emplace(dis[s], s);
    while (!pq.empty()) {
        P p = pq.top();
        pq.pop();
        int v = p.second;
        if (dis[v] < p.first) {
            continue;
        }
        for (auto &e : G[v]) {
            if (dis[e.to] > dis[v] + e.cost) {
                dis[e.to] = dis[v] + e.cost;
                pre[e.to] = v; // 頂点 v を通って e.to にたどり着いた
                pq.emplace(dis[e.to], e.to);
            }
        }
    }
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N, M, s, t;
    cin >> N >> M >> s >> t;
    Graph g(N);
    rep(i, M) {
        ll a, b, c;
        cin >> a >> b >> c;
        g[a].emplace_back(b, c);
    }

    dijkstra(g, s, dis, pre);

    if(dis[t] >= INF) {
        cout << -1 << endl;
        return 0;
    }

    vector<pll> ans;
    ll Y = 0;
    ll now = t;
    while(now != s) {
        ans.emplace_back(pre[now], now);
        now = pre[now];
        Y++;
    }
    reverse(ans.begin(), ans.end());

    cout << dis[t] << " " << Y << endl;
    for(auto p : ans) {
        cout << p.first << " " << p.second << endl;
    }

}
