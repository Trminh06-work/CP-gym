// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1491

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second

vector <vector<int>> diff;

int optimal(int &n, vector <string> &st){
    int ans = 0;

    // (3-x, y) & (x, 3-y) & (3-x, 3-y)
    for (int x = 0; x <= n / 2 - 1; ++x)
        for (int y = n / 2; y <= n - 1; ++y){
            // int diff = 0;
            diff[x][y] += (st[x][y] != st[n - 1 - x][y]);
            diff[x][y] += (st[x][y] != st[x][n - 1 - y]);
            diff[x][y] += (st[x][y] != st[n - 1 - x][n - 1 - y]);
            ans += min(diff[x][y], 4 - diff[x][y]);
        }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, u, x, y; cin >> n >> u;
    vector <string> st(n);
    diff.resize(n, vector<int>(n));
    pair<int, int> d0[4] = {{0, 0}, {0, n / 2}, {n / 2, n / 2}, {n / 2, 0}};
    pair<int, int> d1[4] = {{n / 2 - 1, n / 2 - 1}, {n / 2 - 1, n - 1}, {n - 1, n - 1}, {n - 1, n / 2 - 1}};
    for (int i = 0; i < n; ++i)
        cin >> st[i];

    int ans = optimal(n, st);
    cout << ans << "\n";
    while (u--){
        cin >> x >> y;
        x--; y--;
        if (st[x][y] == '.')
            st[x][y] = '#';
        else
            st[x][y] = '.';

        if (x >= 0 && x <= n / 2 - 1 && y >= n / 2 && y <= n - 1){
            ans -= min(diff[x][y], 4 - diff[x][y]);
            diff[x][y] = 0;
            diff[x][y] += (st[x][y] != st[n - 1 - x][y]);
            diff[x][y] += (st[x][y] != st[x][n - 1 - y]);
            diff[x][y] += (st[x][y] != st[n - 1 - x][n - 1 - y]);
            ans += min(diff[x][y], 4 - diff[x][y]);
        } else {
            for (int i = 0; i < 4; ++i)
                if (x >= d0[i].fi && x <= d1[i].fi && y >= d0[i].se && y <= d1[i].se){
                    int core_x, core_y;
                    switch (i){
                        case 0:
                            core_x = x, core_y = n - 1 - y;
                            break;
                        case 2:
                            core_x = n - 1 - x, core_y = y;
                            break;
                        case 3:
                            core_x = n - 1 - x, core_y = n - 1 - y;
                            break;
                    }
                    ans -= min(diff[core_x][core_y], 4 - diff[core_x][core_y]);
                    diff[core_x][core_y] = 0;
                    diff[core_x][core_y] += (st[core_x][core_y] != st[n - 1 - core_x][core_y]);
                    diff[core_x][core_y] += (st[core_x][core_y] != st[core_x][n - 1 - core_y]);
                    diff[core_x][core_y] += (st[core_x][core_y] != st[n - 1 - core_x][n - 1 - core_y]);
                    ans += min(diff[core_x][core_y], 4 - diff[core_x][core_y]);
                    break;
                }
        }
        cout << ans << "\n";
    }
    return 0;
}