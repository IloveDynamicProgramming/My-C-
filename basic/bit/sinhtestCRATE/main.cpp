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
const int NTEST = 100;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
ll Rand(ll st, ll en)
{
    return st + 1ll * rd() % (en - st + 1);
}

int main()
{
    srand(time(NULL));
    for (int t = 1; t <= NTEST; ++t) {
        ofstream inp("test.inp");
        int n = 5;
        inp << n << '\n';
        for (int i = 1; i <= n; ++i) {
            inp << Rand(1, 10) << ' ' << Rand(1, 10) << '\n';
        }
        inp.close();
        system("trau.exe");
        system("chuan.exe");
        if (system("fc test.out test.ans") != 0) {
            cout << t << " sai!";
            return 0;
        }
        cout << t << " dung\n";
    }
}
