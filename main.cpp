#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second

int genome(char gene){
    switch (gene){
        case 'A':
            return 0;
        case 'C':
            return 1;
        case 'G':
            return 2;
        case 'T':
            return 3;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("cownomics.in",  "r", stdin);
    freopen("cownomics.in", "w", stdout);

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

        for (int j = 0; j < 4; ++j)
            if (spot_gens[i] || plain_gens[i]){
                
            }
    }
    cout << ans;
    return 0;
}