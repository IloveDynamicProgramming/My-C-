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
const int N = 2e4 + 2;
const int M = 2e4 + 2;
int fa[N], si[N], n;
bool ban[N];
ll res;
vector<pii> edge;
vector<ll> ans;
struct query
{
    char typ;
    int id;
} q[M];

void resetDSU()
{
    for (int i = 1; i <= n; ++i) fa[i] = i, si[i] = 1;
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
    res -= (ll)si[x] * si[y];
    fa[y] = x;
    si[x] += si[y];
}

void resetcase()
{
    edge.clear();
    ans.clear();
    memset(ban, false, sizeof ban);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
#ifdef NDT
    freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);
#endif
    int test;
    cin >> test;
    while (test--) {
        resetcase();
        cin >> n;
        edge.pb({-1, -1});
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            edge.pb({u, v});
        }
        int Q;
        cin >> Q;
        for (int i = 1; i <= Q; ++i) {
            cin >> q[i].typ;
            if (q[i].typ == 'R') cin >> q[i].id, ban[q[i].id] = true;
        }
        resetDSU();
        res = n * (n - 1) / 2;
        for (int i = 1; i < edge.size(); ++i) {
            if (ban[i]) continue;
            int u = edge[i].fi, v = edge[i].se;
            if (!Same(u, v))
                Unite(u, v);
        }
        for (int i = Q; i >= 1; --i) {
            if (q[i].typ == 'R') {
                int u = edge[q[i].id].fi, v = edge[q[i].id].se;
                if (!Same(u, v))
                    Unite(u, v);
            }
            else {
                ans.pb(res);
            }
        }
        for (int i = ans.size() - 1; i >= 0; --i) cout << ans[i] << '\n';
        cout << '\n';
    }
}
