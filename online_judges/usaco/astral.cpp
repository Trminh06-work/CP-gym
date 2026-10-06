// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1467

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fi first
#define se second


bool superimpose(int& n, vector <vector<bool>>& a, vector <vector<bool>>& b, vector <vector<int>>& ref){
    // cout << "ORIGIN\n";
    // for (int i = 0; i < n; ++i){
    //     for (int j = 0; j < n; ++j)
    //         cout << a[i][j];
    //     cout << "\n";
    // }

    // cout << "SHIFTED\n";
    // for (int i = 0; i < n; ++i){
    //     for (int j = 0; j < n; ++j)
    //         cout << b[i][j];
    //     cout << "\n";
    // }

    // cout << "SUPERIMPOSE\n";
    // for (int i = 0; i < n; ++i){
    //     for (int j = 0; j < n; ++j)
    //         cout << (a[i][j] | b[i][j]);
    //     cout << "\n";
    // }
    // cout << "\n";


    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j){
            // no star in ref but superimposing gives star
            // the star can disappear in the shifted
            if (a[i][j] && ref[i][j] == 0)
                return false;
            // perhaps star in ref but superimposing gives no star
            if (!(a[i][j] | b[i][j]) && ref[i][j] == 1)
                return false;
            // sure star in ref but one of them does not give no star
            if (!(a[i][j] & b[i][j]) && ref[i][j] == 2)
                return false;
        }
    return true;
}


int solve(int& n, int& a, int& b, vector <vector<int>>& ref){
    // B <=> origin and shifted have stars
    // G <=> origin (0) and shifted (1) or origin (1) and shifted (0)
    // in shifted, a star in origin may either disappear or
    // move by {A, B} so it disappear/appear in other locations

    // cout << "REFERENCE\n";
    // for (int i = 0; i < n; ++i){
    //     for (int j = 0; j < n; ++j)
    //         cout << ref[i][j];
    //     cout << "\n";
    // }
    // cout << "\n";

    // Then start with origin with all pixels set
    vector <vector<bool>> origin(n, vector<bool>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            origin[i][j] = (ref[i][j] >= 1);
    vector <vector<bool>> shifted(n, vector<bool>(n));
    // Now, greedily modify origin -> remove some pixels
    // Only possible when either a > 0 or b > 0
    if (a != 0 || b != 0){
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j){
                if (origin[i][j] == 0) continue; // skip
                int x = i - b, y = j - a;
                if (x < 0 || x >= n || y < 0 || y >= n) continue;
                // cout << i << ' ' << j << " | " << x << " " << y << "\n";
                // ref[i][j] = 'W' => origin[x][y] = 0
                if (ref[i][j] == 0 && origin[x][y]) origin[x][y] = 0;
                // ref[i][j] = 'G' and origin[x][y] = 1
                //      => origin[i][j] = 0
                if (ref[i][j] == 1 && origin[x][y]) origin[i][j] = 0;
                // ref[i][j] = 'B' and origin[x][y] = 0
                //      => origin[x][y] = 1
                if (ref[i][j] == 2 && !origin[x][y]) origin[x][y] = 1;
            }
    }

    // Shift the image
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j){
            int x = i + b, y = j + a;
            if (x < 0 || x >= n || y < 0 || y >= n) continue;
            shifted[x][y] = origin[i][j];
        }
    // Superimpose the origin and shifted images
    if (superimpose(n, origin, shifted, ref)){
        int ans = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                ans += origin[i][j];
        return ans;
    }

    // No possible answers
    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("factory.in", "r", stdin);
    // freopen("factory.out", "w", stdout);

   int t; cin >> t;
   while (t--){
        int n, a, b; cin >> n >> a >> b;
        vector <vector<int>> ref(n, vector<int>(n));
        for (int i = 0; i < n; ++i){
            string st; cin >> st;
            for (int j = 0; j < n; ++j)
                if (st[j] == 'W') ref[i][j] = 0;
                else if (st[j] == 'G') ref[i][j] = 1;
                else ref[i][j] = 2;
        }
        cout << solve(n, a, b, ref) << "\n";
   }


    return 0;
}