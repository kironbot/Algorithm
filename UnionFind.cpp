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
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//
// Union-Find
//
// verified: https://judge.yosupo.jp/problem/unionfind
//


/*
    ・併合時の工夫: union by size
    par[x]: x が根のときは x を含むグループのサイズ (の -1 倍)、そうでないときは親ノード
    issame(x, y): x と y が同じグループにいるか, 計算量はならし O(α(n))
    merge(x, y): x と y を同じグループにする, 計算量はならし O(α(n))
    size(x): x を含むグループの所属メンバー数
*/

struct UnionFind {
    vector<int> par;

    UnionFind(int n) : par(n, -1) { }
    void init(int n) { par.assign(n, -1); }

    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }

    int size(int x) {
        return -par[root(x)];
    }
};

int main() {
    int N, Q; cin >> N >> Q;
    UnionFind uf(N);
    rep(i, Q) {
        ll t, u, v;
        cin >> t >> u >> v;
        if (t == 0) uf.merge(u, v);
        else {
            if (uf.issame(u, v)) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
}