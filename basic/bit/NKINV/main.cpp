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
const int N = 6e4 + 2;
const int MAXV = 6e4;
int n, a[N], bit[N];

void update(int x, int va)
{
    if (x == 0) return;
    for (; x <= MAXV; x += x & -x)
        bit[x] += va;
}

int get(int x)
{
    int res = 0;
    for (; x > 0; x -= x & -x)
        res += bit[x];
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
    int res = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        res += get(MAXV) - get(a[i]);
        update(a[i], 1);
    }
    cout << res;
}
