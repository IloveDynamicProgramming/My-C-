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
const int N = 1e4 + 2;
const int MAXN = 1e4;
int fa[N], p;

void resetDSU()
{
    for (int i = 1; i <= MAXN; ++i) fa[i] = i;
}

int find(int x)
{
    return (x == fa[x] ? x : fa[x] = find(fa[x]));
}

bool same(int x, int y)
{
    return find(x) == find(y);
}

void unite(int x, int y)
{
    x = find(x), y = find(y);
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
    cin >> p;
    resetDSU();
    for (int i = 1; i <= p; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        if (z == 1) {
            if (!same(x, y)) unite(x, y);
        }
        else {
            cout << (same(x, y) ? 1 : 0) << '\n';
        }
    }
}
