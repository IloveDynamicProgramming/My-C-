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
vector<vi> stree;
vector<pii> edge;
int n, fa[N], m;

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

void kruskal(int ban)
{
    stree.pb({});
    resetDSU();
    int CC = n;
    for (int i = 0; i < edge.size(); ++i) {
        if (i == ban) continue;
        int u = edge[i].fi, v = edge[i].se;
        if (!Same(u, v)) {
            Unite(u, v);
            stree.back().pb(i);
            --CC;
        }
    }
    if (CC > 1) stree.pop_back();
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
        edge.pb(mp(u, v));
    }
    kruskal(edge.size());
    for (int i = 0; i < stree[0].size(); ++i) {
        int ban = stree[0][i];
        kruskal(ban);
        if (stree.size() >= 3) break;
    }
    cout << min(3, (int)stree.size()) << '\n';
    for (int i = 0; i < min(3, (int)stree.size()); ++i) {
        for (int j : stree[i]) {
            cout << edge[j].fi << ' ' << edge[j].se << '\n';
        }
    }
}
