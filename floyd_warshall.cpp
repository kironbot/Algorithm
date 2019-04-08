// ワーシャルフロイド法（最短経路）
//
// 計算量：O(V^3)
//

#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL<<60;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main() {
    // 頂点数： n
    long long n;
    // 辺数： m
    long long m;
    cin >> n >> m;

    // 頂点 a[i], b[i]
    // 辺の長さ c[i]
    // 最短距離 dist[i][j]
    vector<long long> a(m), b(m), c(m);
    vector<vector<long long>> dist(n, vector<long long>(n));

    // 頂点a[i]とb[i]の距離がc[i]
    for(int i = 0; i < m; i++) {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--, b[i]--;
    }

    // 最短距離の初期化
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    // 辺がある場合は更新
    for(int i = 0; i < m; i++) {
        chmin(dist[a[i]][b[i]], c[i]);
        chmin(dist[b[i]][a[i]], c[i]);
    }

    // ワーシャルフロイド法
    for(int k = 0; k < n; k++) { // 経由する頂点
        for(int i = 0; i < n; i++){ // スタート
            for(int j = 0; j < n; j++){ // ゴール
                chmin(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}