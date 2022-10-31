#include <bits/stdc++.h>

using namespace std;
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define le(id) (id << 1)
#define ri(id) (id << 1  1)
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
const int N = 1e5 + 2;
int n, b[N], c[N];


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
#ifdef NDT
    freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> b[i];
    for (int i = 1; i <= n; ++i) cin >> c[i];
    sort(b + 1, b + n + 1);
    sort(c + 1, c + n + 1);
    int ib = 1, ic = n, res = INT_MAX;
    while (ib <= n) {
        while (ic > 1 && b[ib] + c[ic] >= 0) {
            res = min(res, abs(b[ib] + c[ic]));
            --ic;
        }
        res = min(res, abs(b[ib] + c[ic]));
        ++ib;
    }
    cout << res;
}
