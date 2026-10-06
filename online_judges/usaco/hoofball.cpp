// Link: https://usaco.org/index.php?page=viewproblem2&cpid=808

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


    freopen("hoofball.in", "r", stdin);
    freopen("hoofball.out", "w", stdout);

    int n; cin >> n;
    vector <int> c(n + 1);
    vector <pair<int, int>> d;
    for (int i = 1; i <= n; ++i){
        int k; cin >> k;
        d.push_back({k, i});
    }
    if (n == 1) {
        cout << 1;
        return 0;
    }

    sort(all(d));

    // for (auto it: d)
    //     cout << it.fi << ' ' << it.se << "\n";
    // cout << "\n";

    c[d[0].se] = d[1].se;
    c[d[n - 1].se] = d[n - 2].se;
    for (int i = 1; i < n - 1; ++i){
        int left_dist = d[i].fi - d[i - 1].fi;
        int right_dist =  d[i + 1].fi - d[i].fi;
        if (left_dist <= right_dist)
            c[d[i].se] = d[i - 1].se;
        else
            c[d[i].se] = d[i + 1].se;
    }

    // for (int i = 1; i <= n; ++i)
    //     cout << i << " : " << c[i] << "\n";
    // cout << "\n";

    vector <int> vis(n + 1);
    for (int i = 1; i <= n; ++i)
        if (!vis[i]){
            vis[i] = i;
            int j = c[i];
            while (vis[j] != i){
                vis[j] = i;
                j = c[j];
            }
        }

    set <int> ans;
    for (int i = 1; i <= n; ++i)
        ans.insert(vis[i]);
    cout << ans.size();


    return 0;
}