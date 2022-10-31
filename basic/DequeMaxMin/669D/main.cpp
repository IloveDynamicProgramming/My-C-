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
const int N = 3e5 + 5;
const int INF = 1e9 + 2;
int n, h[N], L1[N], R1[N], L2[N], R2[N], f[N];
deque<int> dq;
vi pre[N];

void process(int L[], int R[]){
    while (!dq.empty()) dq.pop_back();
    dq.push_back(0);
    h[0] = INF;
    forr(int, i, 1, n)
    {
        while (!dq.empty() && h[dq.back()] <= h[i]) dq.pop_back();
        L[i] = dq.back();
        dq.push_back(i);
    }
    while (!dq.empty()) dq.pop_back();
    dq.push_back(n + 1), h[n + 1] = INF;
    ford(int, i, n, 1)
    {
        while (!dq.empty() && h[dq.back()] <= h[i]) dq.pop_back();
        R[i] = dq.back();
        dq.pb(i);
    }
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
    forr(int, i, 1, n) cin >> h[i];
    process(L1, R1);
    forr(int, i , 1, n) h[i] = -h[i];
    process(L2, R2);
    forr(int, i, 1, n)
    {
        pre[i].pb(i - 1);
        pre[R2[i]].pb(L2[i]);
        pre[R1[i]].pb(L1[i]);
    }
    f[0] = INF;
    f[1] = 0;
    forr(int, i, 2, n)
    {
        f[i] = INF;
        for (int u : pre[i]) {
            f[i] = min(f[i], f[u] + 1);
        }
    }
    cout << f[n];
}
