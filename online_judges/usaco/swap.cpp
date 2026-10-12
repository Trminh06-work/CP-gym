// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1013

// Solution: after two reverses => obtain some cycles
// k <- k % #m where m is the number of nodes in the cycles
// naively traverse N^2 -> #m
// naively traverse N -> exact node after k processes

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

    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);

    int n, k; cin >> n >> k;
    vector <int> adj(n + 1);
    for (int i = 1; i <= n; ++i)
        adj[i] = i;


    for (int kk = 0; kk < 2; ++kk){
        // for (int i = 1; i <= n; ++i)
        //     cout << i << " : " << adj[i] << "\n";
        // cout << "\n";
        int l, r; cin >> l >> r;
        for (int i = 0; i < int((r - l + 1) / 2); ++i){
            // cout << i << " : " << l+i << " " << r-i << " " << adj[l + i] << " " << adj[r - i] << "\n";
            swap(adj[l + i], adj[r - i]);
            // cout << i << " : " << l+i << " " << r-i << " " << adj[l + i] << " " << adj[r - i] << "\n";
        }
    }

    for (int i = 1; i <= n; ++i){
        vector <bool> vis(n + 1);
        vis[i] = true;
        int cnt = 1, j = i;
        while (!vis[adj[j]]){
            j = adj[j];
            vis[j] = true;
            ++cnt;
        }
        for (cnt = k % cnt, j = i; cnt > 0; --cnt, j = adj[j]);
        cout << j << "\n";
    }
    return 0;
}