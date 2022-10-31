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
typedef tuple<int, int, int> tiii;
const int N = 3e5 + 2;
const int MAXV = 1e5 + 1;
int n, bit[N], res[N];
tiii a[N];
stack<int> st;

void update(int x, int va)
{
    for (; x <= MAXV; x += x & -x) {
        bit[x] += va;
    }
}

int get(int x)
{
    int res = 0;
    for (; x > 0; x -= x & -x)
        res += bit[x];
    return res;
}

void chuan()
{
    memset(res, 0, sizeof res);
    sort(a + 1, a + n + 1);
//    for (int i = 1; i <= n; ++i) {
//        cout << get<0>(a[i]) << ' ' << get<1>(a[i]) << ' ' << get<2>(a[i]) << '\n';
//    }
    get<0>(a[0]) = -1;
    for (int i = 1; i <= n; ++i) {
        if (get<0>(a[i]) > get<0>(a[i - 1]))
        {
            while (!st.empty()) {
                update(st.top(), 1);
                st.pop();
            }
        }
        if (get<0>(a[i]) != get<0>(a[i - 1]) || get<1>(a[i]) != get<1>(a[i - 1]))
        {
            int cnt = get(get<1>(a[i])) + st.size();
            res[get<2>(a[i])] = cnt;
        }
        else res[get<2>(a[i])] = res[get<2>(a[i - 1])];
        st.push(get<1>(a[i]));
    }
    for (int i = 1; i <= n; ++i) cout << res[i] << '\n';
}

bool better(tiii a, tiii b)
{
    return (get<0>(a) > get<0>(b) && get<1>(a) >= get<1>(b)) || (get<0>(a) >= get<0>(b) && get<1>(a) > get<1>(b));
}

void trau()
{
    memset(res, 0, sizeof res);
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
//            if (i == 2 || j == 2)
//                int z = 1;
            if (better(a[i], a[j]))
                ++res[i];
            else if (better(a[j], a[i]))
                ++res[j];
        }
    }
    for (int i = 1; i <= n; ++i) cout << res[i] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
//#ifdef NDT
//    freopen("test.inp", "r", stdin);
//    freopen("test.out", "w", stdout);
//#endif
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> get<0>(a[i]) >> get<1>(a[i]);
        ++get<0>(a[i]), ++get<1>(a[i]);
        get<2>(a[i]) = i;
    }
//    trau();

    chuan();
}
