#include <bits/stdc++.h>

using namespace std;
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define le(id) (id << 1)
#define ri(id) (id << 1 | 1)
#define pb push_back
#define pf push_front
typedef long long ll;
typedef long double ld;
typedef double db;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

void binprint(ll x) {
  vi v;
  for (int i = 0; i < 9; ++i) {
    if (x >> i & 1) v.pb(1);
    else v.pb(0);
  }
  reverse(all(v));
  for (int u : v) cerr << u;
  cerr << '\n';
}

int g(int x) {
  return x ^ (x >> 1);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
#ifdef NDT
  freopen("test.inp", "r", stdin);
  //freopen("test.out", "w", stdout);
#endif
  int n = 31 ;
  for (int i = 0; i < n; ++i) {
    int x = g(i);
    binprint(x);
  }
}
