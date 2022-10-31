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
const int N = 1e6 + 2;
int L[N], R[N], a[N], n;
deque<int> dq;

void cleardq()
{
    while (!dq.empty()) dq.pop_back();
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
    forr(int, i, 1, n)
        cin >> a[i];
    cleardq();
    dq.push_back(0);
    a[0] = a[n + 1] = -1;
    forr(int, i, 1, n)
    {
        while (!dq.empty() && a[dq.back()] >= a[i])
            dq.pop_back();
        L[i] = dq.back();
        dq.push_back(i);
    }
    cleardq();
    dq.push_back(n + 1);
    ford(int, i, n, 1)
    {
        while (!dq.empty() && a[dq.back()] >= a[i])
            dq.pop_back();
        R[i] = dq.back();
        dq.push_back(i);
    }
    int res = 0;
    forr(int, i, 1, n)
        if (a[i] <= R[i] - L[i] - 1)
            res = max(res, a[i]);
    cout << res;
}
