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
string s;
vector<pii> even, odd;

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
        cin >> s;
        even.clear(), odd.clear();
        for (int i = 0; i < s.size(); ++i) {
            int t = s[i] - '0';
            if (t & 1)
                odd.pb({i, t});
            else even.pb({i, t});
        }
//        for (pii e : odd) cerr << e.fi << ' ' << e.se << '\n';
//        for (pii e : even) cerr << e.fi << ' ' << e.se << '\n';
        int iodd = 0, ieven = 0;
        while (iodd < odd.size() || ieven < even.size()) {
            if (iodd == odd.size()) {
                cout << even[ieven].se;
                ++ieven;
            }
            else if (ieven == even.size()) {
                cout << odd[iodd].se;
                ++iodd;
            }
            else {
                if (even[ieven].se < odd[iodd].se) {
                    cout << even[ieven].se;
                    ++ieven;
                }
                else {
                    cout << odd[iodd].se;
                    ++iodd;
                }
            }
        }
        cout << '\n';
    }

}
