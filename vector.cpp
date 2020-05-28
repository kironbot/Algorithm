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

// 2次元ベクトル構造体
// <: 偏角ソート
// verify: https://atcoder.jp/contests/abc139/tasks/abc139_f

const double eps = 1e-9;
struct V {
  double x, y;
  V(double x=0, double y=0): x(x), y(y) {}
  V& operator+=(const V& v) { x += v.x; y += v.y; return *this;}
  V operator+(const V& v) const { return V(*this) += v;}
  V& operator-=(const V& v) { x -= v.x; y -= v.y; return *this;}
  V operator-(const V& v) const { return V(*this) -= v;}
  V& operator*=(double s) { x *= s; y *= s; return *this;}
  V operator*(double s) const { return V(*this) *= s;}
  V& operator/=(double s) { x /= s; y /= s; return *this;}
  V operator/(double s) const { return V(*this) /= s;}
  double dot(const V& v) const { return x*v.x + y*v.y;}
  double cross(const V& v) const { return x*v.y - v.x*y;}
  double norm2() const { return x*x + y*y;}
  double norm() const { return sqrt(norm2());}

  int ort() const { // orthant
    if (abs(x) < eps && abs(y) < eps) return 0;
    if (y > 0) return x>0 ? 1 : 2;
    else return x<0 ? 3 : 4;
  }
  bool operator<(const V& v) const {
    int o = ort(), vo = v.ort();
    if (o != vo) return o < vo;
    return cross(v) > 0;
  }
};
istream& operator>>(istream& is, V& v) {
  is >> v.x >> v.y; return is;
}
ostream& operator<<(ostream& os, const V& v) {
  os<<"("<<v.x<<","<<v.y<<")"; return os;
}

int main() {
    int n;
    cin >> n;
    vector<V> v(n);
    rep(i,n) cin >> v[i];
    sort(v.begin(), v.end());
    double ans = 0;
    rep(l,n) {
        ll r = l;
        V now;
        rep(i,n) {
            now += v[r];
            chmax(ans, now.norm());
            r = (r+1)%n;
        }
    }

    cout.precision(20);
    cout << ans << endl;
}