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

//  LCA(G, root): 木 G に対する根を root として Lowest Common Ancestor を求める構造体
//  verify: https://judge.yosupo.jp/problem/lca
//  query(u,v): u と v の LCA を求める。計算量 O(logn)
//  前処理: O(nlogn)時間, O(nlogn)空間

using Graph = vector<vector<long long>>;
struct LCA {
    vector<vector<int>> parent;  // parent[k][u]:= u の 2^k 先の親
    vector<int> dist;            // root からの距離
    LCA(const Graph &G, int root = 0) { init(G, root); }
    // 初期化
    void init(const Graph &G, int root = 0) {
        int V = G.size();
        int K = 1;
        while ((1 << K) < V) K++;
        parent.assign(K, vector<int>(V, -1));
        dist.assign(V, -1);
        dfs(G, root, -1, 0);
        for (int k = 0; k + 1 < K; k++) {
            for (int v = 0; v < V; v++) {
                if (parent[k][v] < 0) {
                    parent[k + 1][v] = -1;
                } else {
                    parent[k + 1][v] = parent[k][parent[k][v]];
                }
            }
        }
    }
    // 根からの距離と1つ先の頂点を求める
    void dfs(const Graph &G, int v, int p, int d) {
        parent[0][v] = p;
        dist[v] = d;
        for (auto u : G[v]) {
            if (u != p) dfs(G, u, v, d + 1);
        }
    }
    int query(int u, int v) {
        if (dist[u] < dist[v]) swap(u, v);  // u の方が深いとする
        int K = parent.size();
        // LCA までの距離を同じにする
        for (int k = 0; k < K; k++) {
            if ((dist[u] - dist[v]) >> k & 1) {
                u = parent[k][u];
            }
        }
        // 二分探索で LCA を求める
        if (u == v) return u;
        for (int k = K - 1; k >= 0; k--) {
            if (parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll N, Q; cin >> N >> Q;
    Graph g(N);
    for(ll i = 1; i < N; i++) {
        ll p; cin >> p;
        g[i].push_back(p);
        g[p].push_back(i);
    }
    LCA lca(g);
    rep(i,Q) {
        ll u, v;
        cin >> u >> v;
        cout << lca.query(u, v) << endl;
    }
}
