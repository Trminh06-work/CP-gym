// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1565

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fi first
#define se second

vector <pair<ll, ll>> a;
int n;

ll greed(int i, ll v){
    if (i < 0 || v <= 0) return 0;

    ll ans = 0;
    ll k = (1LL << a[i].fi);
    ll num = v / k;
    ans = greed(i - 1, v - num * k) + num * a[i].se;
    ans = min(ans, greed(i - 1, v - (num + 1) * k) + (num + 1) * a[i].se);
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // INTERESTING
    // 1 < n < 10^5 => 2^N overflows
    // in fact, we can only process for those n <= 32
    // hence, n > 32 is never needed

    // freopen("factory.in", "r", stdin);
    // freopen("factory.out", "w", stdout);

    int q; cin >> n >> q;
    ll v;
    cin >> v;
    a.push_back({0, v});
    for (int i = 1; i < n; ++i){
            cin >> v;
             // above 32 is unnecessary and never be chosen
            if (i > 32) continue;
            pair<ll, ll> u = a.back();
            // beneficial whenever 2^i * v < 2^{u.fi} * u.se
            // where i = u.fi + k => k = i - u.fi
            //  => v < 2^{i - u.fi} * u.se
            if (v < (1LL << (1LL * i - u.fi)) * u.se)
                a.push_back({i, v});
    }

//    for (const auto& [x, y]: a) cout << x << " " << y << "\n";
//    cout << "\n";

   n = a.size();
   while (q--){
        cin >> v;
        // make the most, from back() -> front()
        // at least `x` => try to reduce #buckets as many as possible
        cout << greed(min(n - 1, 32), v) << "\n";
   }

    return 0;
}