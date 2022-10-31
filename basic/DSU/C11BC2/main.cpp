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
int fa[N], n, m;

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
	resetDSU();
	for (int i = 2; i <= n; ++i) {
        int x, k;
        cin >> x >> k;
        if (k < 2) {
            if (!Same(x, i))
                Unite(x, i);
        }
	}
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        if (Same(x, y)) cout << "NO\n";
        else cout << "YES\n";
    }
}
