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
#define mp make_pair
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const int N = 1e3 + 2;
vi adj[N], savecycle;
int n, m, vis[N], cycle[N], fa[N];
vector<pii> incycle, res, edge;
bool foundcycle;

void DFS(int u, int pr, int time)
{
    vis[u] = 1;
    cycle[time] = u;
    for (int v : adj[u]) {
        if (foundcycle) return;
        if (v == pr) continue;
        if (vis[v]) {
            if (vis[v] == 1) {
                for (int i = time;; --i) {
                    savecycle.pb(cycle[i]);
                    if (cycle[i] == v) break;
                }
                foundcycle = true;
            }
            continue;
        }
        DFS(v, u, time + 1);
    }
    vis[u] = 2;
}

void resetDSU()
{
    for (int i = 1; i <= n; ++i) fa[i] = i;
}

int Find(int x)
{
    return (x == fa[x] ? x : fa[x] = Find(fa[x]));
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

void putans(pii e)
{
    cout << e.fi << ' ' << e.se << '\n';
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
        cin >> u >> v;
        if (u > v) swap(u, v);
        adj[u].pb(v);
        adj[v].pb(u);
        edge.pb(mp(u, v));
    }
    foundcycle = false;
    for (int i = 1; i <= n; ++i) {
        if (vis[i] == 0)
            DFS(i, i, 1);
        if (foundcycle) break;
    }
    for (int i = 0; i < savecycle.size(); ++i) {
        int u = savecycle[i], v = savecycle[(i + 1) % (int)savecycle.size()];
        incycle.pb(mp(u, v));
    }
    resetDSU();
    for (pii e : incycle) {
        int u = e.fi, v = e.se;
        if (!Same(u, v)) {
            Unite(u, v);
        }
    }
    for (pii e : edge) {
        int u = e.fi, v = e.se;
        if (!Same(u, v))
        {
            Unite(u, v);
            res.pb(mp(u, v));
        }
    }
    cout << 3 << '\n';
    for (int i = 0; i < 3; ++i) {
        for (pii e : res) putans(e);
        for (int j = 0; j < incycle.size(); ++j) {
            if (j == i) continue;
            putans(incycle[j]);
        }
    }
}
