// Link: https://codeforces.com/contest/1808/problem/B

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("backforth.in", "r", stdin);
    // freopen("backforth.out", "w", stdout);

    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector<int>> c(n, vector<int>(m));
        for (int i = 0; i < n; ++i)
            for (int& card: c[i]) cin >> card;
        if (n == 1){
            cout << 0 << '\n';
            continue;
        }

        // sort each coordinate in 0 -> m - 1
        // for each i: 0 -> m -1 => |x_i - x_{i - 1}| x (n - i - 1) x (i + 1)
        ll total = 0;
        // for (int i = 0; i < n; ++i)
        //     for (int j = i + 1; j < n; ++j)
        //         for (int k = 0; k < m; ++k)
        //             total += abs(c[i][k] - c[j][k]);

        for (int k = 0; k < m; ++k){
            vector <int> tmp;
            for (int i = 0; i < n; ++i) tmp.push_back(c[i][k]);
            sort(all(tmp));
            // for (int& v: tmp) cout << v << ' ';
            // cout << "\n\n";
            for (int i = 0; i < n - 1; ++i){
                // cout << i << ' ' << abs(tmp[i] - tmp[i + 1]) << ' ' << (n - i - 1) << ' ' << (i + 1) << "\n";
                total += 1LL * abs(tmp[i] - tmp[i + 1]) * (n - i - 1) * (i + 1);
            }
        }
        cout << total << '\n';
    }

    return 0;
}