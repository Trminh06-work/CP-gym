// Link: https://usaco.org/index.php?page=viewproblem2&cpid=689

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fi first
#define se second

vector <vector<bool>> f;
int n;
int dx[3] = {0, -1, 0};
int dy[3] = {-1, -1, 0};

void flip(int& x, int &y){
    for (int i = 0; i <= x; ++i)
        for (int j = 0; j <= y; ++j)
            f[i][j] = !f[i][j];
}

void print(){
    cout << "\n";
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j)
            cout << f[i][j];
        cout << "\n";
    }
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("cowtip.in", "r", stdin);
    freopen("cowtip.out", "w", stdout);

    cin >> n;
    f.resize(n, vector<bool>(n));
    string st;
    for (int i = 0; i < n; ++i){
        cin >> st;
        for (int j = 0; j < n; ++j)
            f[i][j] = (st[j] == '1');
    }

    int ans = 0;
    for (int i = n - 1; i >= 0; --i){
        for (int j = n - 1; j >= 0; --j)
            if (f[i][j]){
                flip(i, j);
                ++ans;
                // print();
            }
    }
    cout << ans;


    return 0;
}