// Link: https://usaco.org/index.php?page=viewproblem2&cpid=739

// This task is simply taking the combination of genes and compare if it could
// distinguish the spotty from the plain cows.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);

    int n, m; cin >> n >> m;
    vector <string> spot(n), plain(n);
    for (auto& cow: spot) cin >> cow;
    for (auto& cow: plain) cin >> cow;

    int ans = 0;
    for (int i = 0; i < m; ++i)
        for (int j = i + 1; j < m; ++j)
            for (int k = j + 1; k < m; ++k){
                set <string> genes;
                for (string& st: spot){
                    string s = string{st[i], st[j], st[k]};
                    genes.insert(s);
                }
                bool diff = true;
                for (string &st: plain){
                    string s = string{st[i], st[j], st[k]};
                    if (genes.count(s) > 0){
                        diff = false;
                        break;
                    }
                }
                ans += diff;
            }
    cout << ans;
    return 0;
}