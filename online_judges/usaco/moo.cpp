// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1468

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fi first
#define se second


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("notlast.in", "r", stdin);
    // freopen("notlast.out", "w", stdout);

    int n; cin >> n;
    vector <int> a(n);
    map<int, int> mp;
    map<int, bool> vis;
    int non_unique = 0;
    for (auto& v: a) cin >> v;

    for (int i = n - 1; i >= 0; --i){
        mp[a[i]]++;
        if (mp[a[i]] == 2) non_unique++;
    }

    ll ans = 0;
    for (int i = 0; i < n - 2;){
        if (a[i] != a[i + 1]){
            mp[a[i]]--;
            if (mp[a[i]] == 1) non_unique--;
            if (!vis[a[i]]){
                ans += 1LL * non_unique;
                vis[a[i]] = true;
                ans -= (mp[a[i]] > 1);
            }
            ++i;
        } else {
            while (i < n - 2 && a[i] == a[i + 1]){
                mp[a[i]]--;
                if (mp[a[i]] == 1) non_unique--;
                ++i;
            }
        }
        // cout << a[i] << ' ' << non_unique << ' ' << ans << "\n";
    }

    cout << ans;
    return 0;
}