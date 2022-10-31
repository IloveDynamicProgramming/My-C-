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
const int N = 17000 + 2;
int n, k, a[N];
deque<int> dq;

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
        while (!dq.empty()) dq.pop_back();
        cin >> n >> k;
        forr(int, i, 1, n) cin >> a[i];
        forr(int, i, 1, n)
        {
            while (!dq.empty() && dq.front() < i - k + 1)
                dq.pop_front();
            while (!dq.empty() && a[dq.back()] >= a[i])
                dq.pop_back();
            dq.push_back(i);
            if (i >= k) {
                cout << a[dq.front()] << ' ';
            }
        }
        cout << '\n';
    }
}
