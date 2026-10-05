// Link: https://usaco.org/index.php?page=viewproblem2&cpid=940

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

    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);

    int n; cin >> n;
    vector <vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i){
        int a, b; cin >> a >> b;
        // revert the direction
        adj[b - 1].push_back(a - 1);
    }

    // assume a node is the sink
    for (int i = 0; i < n; ++i){
        queue <int> q;
        vector <int> vis(n);
        q.push(i);
        // bfs
        while (!q.empty()){
            int u = q.front();
            q.pop();
            vis[u] = true;
            for (int& v: adj[u])
                if (!vis[v]) q.push(v);
        }
        // check if all other nodes are visited
        bool ok = true;
        for (int i = 0; i < n; ++i)
            ok &= vis[i];
        // Yes => comply with problem's definition,
        // hence a sink
        if (ok) {
            cout << i + 1;
            return 0;
        }
    }
    cout << -1;

    return 0;
}