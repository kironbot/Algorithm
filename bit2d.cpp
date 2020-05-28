/* BIT2D:
    初期値は全て 0
    ・add(h,w,x): (h,w) に x を加算する
    ・sum(h,w): 1≦i≦h かつ 1≦j≦w の範囲の合計値を求める
    ・query(h1,w1,h2,w2): h1≦i<h2 かつ w1≦j<w2 の範囲の合計値を求める(1-indexed)
    計算量は全て O(logW * logH)
*/
template <typename T>
struct BIT2D {
    int H, W;
    vector<vector<T>> bit;  // データの格納先
    BIT2D(int H_, int W_) { init(H_, W_); }
    void init(int H_, int W_) {
        H = H_ + 1;
        W = W_ + 1;
        bit.assign(H, vector<T>(W, 0));
    }
    void add(int h, int w, T x) {
        for (int i = h; i < H; i += (i & -i)) {
            for (int j = w; j < W; j += (j & -j)) {
                bit[i][j] += x;
            }
        }
    }
    // 1≦i≦h かつ 1≦j≦w
    T sum(int h, int w) {
        T s(0);
        for (int i = h; i > 0; i -= (i & -i)) {
            for (int j = w; j > 0; j -= (j & -j)) {
                s += bit[i][j];
            }
        }
        return s;
    }
    // h1≦i<h2 かつ w1≦j<w2
    T query(int h1, int w1, int h2, int w2) {
        return sum(h2 - 1, w2 - 1) - sum(h2 - 1, w1 - 1) - sum(h1 - 1, w2 - 1) + sum(h1 - 1, w1 - 1);
    }
};
