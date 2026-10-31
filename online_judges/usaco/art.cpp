// Link: https://usaco.org/index.php?page=viewproblem2&cpid=737

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fi first
#define se second


bool intersect(vector <int> &a, vector <int> &b){
    int bl_ax = a[0], bl_ay = a[1], tr_ax = a[2], tr_ay = a[3];
    int bl_bx = b[0], bl_by = b[1], tr_bx = b[2], tr_by = b[3];

    // no overlap
    // cout << "\n";
    // cout << bl_ax << ' ' << bl_ay << " " << tr_ax << " " << tr_ay << "\n";
    // cout << bl_bx << ' ' << bl_by << " " << tr_bx << " " << tr_by << "\n";
	if (bl_ax > tr_bx || tr_ax < bl_bx || bl_ay > tr_by || tr_ay < bl_by)
		return false;
	else
		return true;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("art.in", "r", stdin);
    freopen("art.out", "w", stdout);

    int n; cin >> n;
    vector <vector<int>> canvas(n + 1, vector <int>(n + 1));
    vector <pair<int, int>> bl(10, {100, 100});
    vector <pair<int, int>> tr(10);

    for (int i = n; i > 0; --i){
        string st; cin >> st;
        for (int j = 1; j <= n; ++j){
            int k = int(st[j - 1] - '0');
            canvas[i][j] = k;
            // bl[k].fi = min(bl[k].fi, j);
            // bl[k].se = min(bl[k].se, i);
            // tr[k].fi = max(tr[k].fi, j);
            // tr[k].se = max(tr[k].se, i);
        }
    }

    for (int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            // cout << canvas[i][j] << ' ';
            int k = canvas[i][j];
            bl[k].fi = min(bl[k].fi, i);
            bl[k].se = min(bl[k].se, j);
            tr[k].fi = max(tr[k].fi, i);
            tr[k].se = max(tr[k].se, j);
        }
        // cout << "\n";
    }
    // cout << "\n";

    // for (int i = 1; i < 10; ++i)
    //     if (tr[i].fi != 0){
    //         cout << i << " : " << bl[i].fi << " " << bl[i].se << ' ' << tr[i].fi << ' ' << tr[i].se << "\n";
    //     }
    // cout << "\n";

    vector <bool> first(10);
    for (int i = 1; i < 10; ++i){
        vector <int> a = {bl[i].fi, bl[i].se, tr[i].fi, tr[i].se};
        if (tr[i].fi != 0) {
            first[i] = true;
            for (int j = 1; j < 10; ++j){
                vector <int> b = {bl[j].fi, bl[j].se, tr[j].fi, tr[j].se};
                if (i == j || tr[i].fi == 0 || !intersect(a, b)) continue;
                // cout << i << ' ' << j << "\n";
                for (int kx = bl[j].fi; kx <= tr[j].fi; ++kx)
                    for (int ky = bl[j].se; ky <= tr[j].se; ++ky)
                        first[i] = (first[i] & (canvas[kx][ky] != i));
            }
        }
    }
    int ans = 0;
    for (int i = 1; i < 10; ++i)
        ans += first[i];
    cout << ans;
    return 0;
}