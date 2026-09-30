// Link: https://usaco.org/index.php?page=viewproblem2&cpid=713

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("cowqueue.in", "r", stdin);
    freopen("cowqueue.out", "w", stdout);

    int n; cin >> n;
    vector <pair<int, int>> cows(n);
    for (auto& c: cows) {
        cin >> c.fi >> c.se;
        c.se += c.fi;
    }

    sort(all(cows));

    // for (auto& c: cows)
    //     cout << c.fi << ' ' << c.se << "\n";
    // cout << "\n";
    for (int i = 1; i < n; ++i)
        if (cows[i - 1].se > cows[i].fi){
            int gap = cows[i - 1].se - cows[i].fi;
            int dist = cows[i].se - cows[i].fi;
            cows[i].fi += gap;
            cows[i].se = cows[i].fi + dist;
        }
    cout << cows[n - 1].se;
    return 0;
}