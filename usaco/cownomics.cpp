// Link: https://usaco.org/index.php?page=viewproblem2&cpid=736

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second

int genome(char gene){
    int id = 0;
    switch (gene){
        case 'A':
            id = 0;
            break;
        case 'C':
            id = 1;
            break;
        case 'G':
            id = 2;
            break;
        case 'T':
            id = 3;
            break;
    }
    return id;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);

    int n, m; cin >> n >> m;
    vector <string> spot(n);
    vector <string> plain(n);

    for (auto& cow: spot) cin >> cow;
    for (auto& cow: plain) cin >> cow;

    int ans = 0;
    for (int i = 0; i < m; ++i){
        // A, C, G, T -> 0, 1, 2, 3
        bool spot_gens[4] = {};
        bool plain_gens[4] = {};

        for (auto& cow: spot) spot_gens[genome(cow[i])] = true;
        for (auto& cow: plain) plain_gens[genome(cow[i])] = true;

        bool diff = true;
        for (int j = 0; j < 4; ++j){
            // cout << i << " " << j << " " <<  spot_gens[j] << " " << plain_gens[j] << "\n";
            if (spot_gens[j] || plain_gens[j]){
                // cout << i << " " << j << " " << spot_gens[j] << " " << plain_gens[j] << "\n";
                diff &= (spot_gens[j] ^ plain_gens[j]);
            }
        }
        ans += diff;
        // cout << i << ' ' << ans << '\n';
    }
    cout << ans;
    return 0;
}