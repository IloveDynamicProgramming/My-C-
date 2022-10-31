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
const int M = 1e5 + 2;
const int N = 3e5 + 2;
const int MAXV = 1e5;
vi node[M], bit[M];
int n;
pii a[N];

void update(int x, int y, int va)
{
    for (; x <= MAXV; x += x & -x)
        for (int y1 = y; y1 <= MAXV; y1 += y1 & -y1)
            bit[x][y1] += va;
}

int get(int x, int y)
{
    int res = 0;
    for (; x > 0; x -= x & -x) {
        for (int y1 = y; y1 > 0; y1 -= y1 & -y1)
            res += bit[x][y1];
    }
    return res;
}

void fakeupdate(int x, int y)
{
    for (; x <= MAXV; x += x & -x)
        node[x].pb(y);
}

void fakeget(int x, int y)
{
    for (; x > 0; x -= x & -x)
        node[x].pb(y);
}

void update2d(int x1, int y1, int va)
{
    for (int x = x1; x <= MAXV; x += x & -x) {
        for (int y = lower_bound(node[x].begin(), node[x].end(), y1) - node[x].begin() + 1; y <= node[x].size(); y += y & -y) {
            bit[x][y - 1] += va;
        }
    }
}

int get2d(int x1, int y1)
{
    int res = 0;
    for (int x = x1; x > 0; x -= x & -x)
    {
        for (int y = lower_bound(node[x].begin(), node[x].end(), y1) - node[x].begin() + 1; y > 0; y -= y & -y) {
            res += bit[x][y - 1];
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
//#ifdef NDT
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
//#endif
	cin >> n;
	for (int i = 1; i <= n; ++i) {
        cin >> a[i].fi >> a[i].se;
        ++a[i].fi, ++a[i].se;
        fakeupdate(a[i].fi, a[i].se);
//        fakeget(a[i].fi, a[i].se);
        fakeget(a[i].fi - 1, a[i].se);
        fakeget(a[i].fi, a[i].se - 1);
        fakeget(a[i].fi, a[i].se);
	}
	for (int i = 1; i <= MAXV; ++i) {
        bit[i].resize(node[i].size() + 2);
	}
	for (int i = 1; i <= n; ++i) {
        update2d(a[i].fi, a[i].se, 1);
	}
	for (int i = 1; i <= n; ++i) {
        cout << get2d(a[i].fi, a[i].se - 1) + get2d(a[i].fi - 1, a[i].se) - get2d(a[i].fi, a[i].se) << '\n';
	}
}
