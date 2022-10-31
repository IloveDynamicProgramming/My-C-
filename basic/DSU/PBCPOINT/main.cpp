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
const pii base[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const int N = 2e3 + 2;
const int offset = 1e3;
int n, d[N][N], maxy, maxx, minx, miny;

bool valid(int x, int y)
{
    return (x >= minx && x <= maxx  && y >= miny && y <= maxy);
}

void trau()
{
    maxx = maxy = -1e6;
    minx = miny = 1e6;
    queue<pii> red;
    for (int i = 1; i <= n; ++i) {
        int x, y;
        cin >> x >> y;
        x += offset;
        y += offset;
        maxx = max(maxx, x);
        minx = min(minx, x);
        maxy = max(maxy, y);
        miny = min(miny, y);
        d[x][y] = true;
        red.push({x, y});
    }
    while (!red.empty()) {
        int x = red.front().fi, y = red.front().se; red.pop();
        for (int i = 0; i < 4; ++i) {
            int tx = base[i].fi, ty = base[i].se;
            for (int j = 1;; ++j) {
                int x1 = x + tx * j, y1 = y + ty * j;
                if (!valid(x1, y1)) break;
                if (d[x1][y1]) {
                    for (int k = 1; k < j; ++k) {
                        int x2 = x + tx * k, y2 = y + ty * k;
                        d[x2][y2] = true;
                        red.push({x2, y2});
                    }
                    break;
                }
            }
        }
    }
    int res = 0;
    for (int i = 0; i <= 2e3; ++i) {
        for (int j = 0; j <= 2e3; ++j) {
            res += d[i][j];
        }
    }
    cout << res << '\n';
}

void chuan()
{
    for (int i = 1; i <= n; ++i) {

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
    trau();
//    chuan();
}
