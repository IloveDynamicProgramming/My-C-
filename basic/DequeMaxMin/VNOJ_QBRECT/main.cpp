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
const int INF = 1e6 + 2;
const int N = 1e3 + 5;
int n, m, a[N][N], d[N][N], L[N], R[N];
deque<int> dq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
#ifdef NDT
    freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);
#endif
    cin >> m >> n;
    forr(int, i, 1, m)
        forr(int, j, 1, n)
        {
            cin >> a[i][j];
        }
    forr(int, j, 1, n)
        forr(int, i, 1, m)
        {
            if (a[i][j] == 1)
                d[i][j] = d[i - 1][j] + 1;
            else d[i][j] = 0;
        }
    int res = 0;
    forr(int, i, 1, m)
    {
        while (!dq.empty()) dq.pop_back();
        dq.push_back(0);
        d[i][0] = -1;
        forr(int, j, 1, n)
        {
            while (!dq.empty() && d[i][dq.back()] >= d[i][j])
                dq.pop_back();
            L[j] = dq.back();
            dq.push_back(j);
        }
        while (!dq.empty()) dq.pop_back();
        dq.push_back(n + 1);
        d[i][n + 1] = -1;
        ford(int, j, n, 1)
        {
            while (!dq.empty() && d[i][dq.back()] >= d[i][j])
                dq.pop_back();
            R[j] = dq.back();
            dq.push_back(j);
            if (d[i][j] < INF)
                res = max(res, d[i][j] * (R[j] - L[j] - 1));
        }
    }
    cout << res << '\n';
}
