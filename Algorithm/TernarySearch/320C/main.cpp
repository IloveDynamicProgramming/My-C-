#include <bits/stdc++.h>

using namespace std;
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define le(id) (id << 1)
#define ri(id) (id << 1  1)
#define forr(type, i, l, r) for (type i = (l); i <= (r); ++i)
#define ford(type, i, r, l) for (type i = (r); i >= (l); --i)
#define pb push_back
#define pf push_front
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int N = 2e5 + 2;
set<ld> s;
int n, a[N];

ld calc(double x)
{
    s.clear();
    ld res = 0, maxV = 0, minV = 0, S = 0;
    for (int i = 1; i <= n; ++i) {
        S += (ld)a[i] - x;
        res = max(res, abs(maxV - S));
        res = max(res, abs(minV - S));
        maxV = max(maxV, S);
        minV = min(minV, S);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
#ifdef NDT
    freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    double l = -INF, r = INF;
    for (int t = 1; t <= 200; ++t) {
        double m1 = (l + l + r) / 3;
        double m2 = (l + r + r) / 3;
        ld t1 = calc(m1);
        ld t2 = calc(m2);
        if (t1 < t2) r = m2;
        else l = m1;
    }
    cout << fixed << setprecision(9) << calc(l) << '\n';
}

