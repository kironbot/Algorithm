// BFS（最短経路）
//
// 計算量：O(|V| + |E|)
//

#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL<<60;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main() {
    // 頂点数n, 辺数m
    int n, m;
    cin >> n >> m;

    // グラフ
    vector<vector<int>> G(n);

    // 頂点aからbに辺を張る（無向グラフ）
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        // a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // 初期ノードからの距離．未訪問は-1で初期化．
    vector<int> dist(n, -1);
    // BFSのためのキュー
    queue<int> que;

    // 初期条件（頂点0からスタート）
    dist[0] = 0;
    que.push(0);

    // BFS
    while(!que.empty()) {
        int cur = que.front(); // キューの先頭から取り出す
        que.pop();

        // 現在の頂点curからいける頂点を訪問する
        for(auto nv : G[cur]) {
            if (dist[nv] != -1) continue; // すでに訪問済みの場合はスキップ

            dist[nv] = dist[cur] + 1;
            que.push(nv);
        }
    }

    // 結果出力
    for(int v = 0; v < n; v++) {
        cout << "0 - " << v << ": " << dist[v] << endl;
    }
}