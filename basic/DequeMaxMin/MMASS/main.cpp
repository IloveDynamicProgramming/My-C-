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
int it;
string s;

int va(char ch)
{
    if (ch == 'O') return 16;
    if (ch == 'H') return 1;
    if (ch == 'C') return 12;
}

int process()
{
    int res = 0;
    while (s[it] != ')') {
        if (s[it] == '(')
            ++it, res += process();
        else
        {
            int tmp = va(s[it]);
            if (s[it + 1] >= '0' && s[it + 1] <= '9')
                ++it, tmp *= (s[it] - '0');
            res += tmp;
        }
        ++it;
    }
    if (s[it + 1] >= '0' && s[it + 1] <= '9') {
        ++it;
        return res * (s[it] - '0');
    }
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
	cin >> s;
    s = '(' + s + ')';
    cerr << s << '\n';
    it = 1;
    cout << process();
}
