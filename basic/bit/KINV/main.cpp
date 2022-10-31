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
typedef pair<int, ll> pil;
const int N = 1e4 + 2;
const int mod = 1e9;
vector<pil> v[2];
int n, K;
ll bit[N], a[N];

ll get(int x)
{
    ll res = 0;
    for (; x > 0; x -= x & -x)
        res = (res + bit[x]) % mod;
    return res;
}

void update(int x, ll va)
{
    for (; x <= n; x += x & -x)
        bit[x] = (bit[x] + va) % mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
#ifdef NDT
    freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);
#endif
	cin >> n >> K;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = n; i >= 1; --i) v[0].pb(mp(i, 1));
	for (int k = 2; k <= K; ++k) {
        int id = (k & 1);
        memset(bit, 0, sizeof bit);
        for (int i = 0; i < v[id].size(); ++i) {
            int j = v[id][i].fi;
            ll presum = v[id][i].se;
            ll cursum = get(a[j] - 1);
            update(a[j], presum);
            if (cursum == 0) continue;
            v[!id].pb(mp(j, cursum));
        }
        v[id].clear();
	}
	ll res = 0;
	for (pil u : v[(K + 1) & 1]) {
        res = (res + u.se) % mod;
	}
	cout << res;
}
