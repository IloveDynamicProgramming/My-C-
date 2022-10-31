#include <bits/stdc++.h>

using namespace std;
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define le(id) (id << 1)
#define ri(id) (id << 1 | 1)
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
typedef tuple<int, int, int> tiii;
const int N = 1e5 + 3;
int fa[N], n;
pii x[N], y[N], z[N];
vector<tiii> edge;

bool cmp(tiii a, tiii b)
{
    return get<0>(a) < get<0>(b);
}

void resetDSU()
{
    for (int i = 1; i <= n; ++i) fa[i] = i;
}

int Find(int x)
{
    if (x == fa[x]) return x;
    return fa[x] = Find(fa[x]);
}

bool Same(int x, int y)
{
    return Find(x) == Find(y);
}

void Unite(int x, int y)
{
    x = Find(x), y = Find(y);
    fa[y] = x;
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
    for (int i = 1; i <= n; ++i)
    {
        cin >> x[i].fi >> y[i].fi >> z[i].fi;
        x[i].se = y[i].se = z[i].se = i;
    }
    sort(x + 1, x + n + 1);
    sort(y + 1, y + n + 1);
    sort(z + 1, z + n + 1);
    for (int i = 2; i <= n; ++i) {
        edge.pb(make_tuple(x[i].fi - x[i - 1].fi, x[i].se, x[i - 1].se));
        edge.pb(make_tuple(y[i].fi - y[i - 1].fi, y[i].se, y[i - 1].se));
        edge.pb(make_tuple(z[i].fi - z[i - 1].fi, z[i].se, z[i - 1].se));
    }
    sort(all(edge), cmp);
    resetDSU();
    int res = 0;
    for (tiii e : edge) {
        int w = get<0>(e), u = get<1>(e), v = get<2>(e);
        if (!Same(u, v))
        {
            Unite(u, v);
            res += w;
        }
    }
    cout << res << '\n';
}
