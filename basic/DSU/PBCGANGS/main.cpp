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
const int N = 1e3 + 5;
vector<pii> edge;
int n, m, fa[N];
vi ene[N];

void resetDSU()
{
    for (int i = 1; i <= n; ++i) fa[i] = i;
}

int Find(int x)
{
    return x == fa[x] ? x : fa[x] = Find(fa[x]);
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
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        char typ;
        cin >> typ >> u >> v;
        if (typ == 'F')
            edge.pb({u, v});
        else {
            ene[u].pb(v);
            ene[v].pb(u);
        }
    }
    for (int i = 1; i <= n; ++i) {
        int lim = ene[i].size();
        for (int j1 = 0; j1 < lim - 1; ++j1) {
            for (int j2 = j1 + 1; j2 < lim; ++j2) {
                edge.pb({ene[i][j1], ene[i][j2]});
            }
        }
    }
    resetDSU();
    int CC = n;
    for (pii e : edge)
    {
        int u = e.fi, v = e.se;
        if (!Same(u, v)) {
            Unite(u, v);
            --CC;
        }
    }
    cout << CC << '\n';
}
