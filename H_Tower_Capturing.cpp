#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 998244353;
const int MAXN = 2005;
ll fac[MAXN], inv[MAXN], invfac[MAXN];

struct Point {
    ll x, y;
    int id;
    bool operator<(const Point &rhs) const {
        if (x != rhs.x) return x < rhs.x;
        return y < rhs.y;
    }
};

ll cross(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

ll C(int n, int k) {
    if (k > n || k < 0) return 0;
    return fac[n] * invfac[k] % MOD * invfac[n - k] % MOD;
}

ll power(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void init() {
    fac[0] = inv[0] = invfac[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = power(i, MOD - 2);
        invfac[i] = invfac[i - 1] * inv[i] % MOD;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    init();
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<Point> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].x >> a[i].y;
            a[i].id = i;
        }
        sort(a.begin(), a.end());
        vector<Point> up, down;
        for (int i = 0; i < n; i++) {
            while (up.size() > 1 && cross(up[up.size() - 2], up.back(), a[i]) >= 0) up.pop_back();
            while (down.size() > 1 && cross(down[down.size() - 2], down.back(), a[i]) <= 0) down.pop_back();
            up.push_back(a[i]);
            down.push_back(a[i]);
        }
        vector<int> hull;
        for (auto &p : up) hull.push_back(p.id);
        for (int i = (int)down.size() - 2; i > 0; i--) hull.push_back(down[i].id);
        int m = hull.size();
        ll ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                int l = j - i - 1, r = m - 2 - l;
                ans += C(n - 2, l) * C(n - l - 2, r) % MOD;
                ans %= MOD;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}