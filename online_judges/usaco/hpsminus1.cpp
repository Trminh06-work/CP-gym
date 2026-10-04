// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1515

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

    // freopen("socdist1.in", "r", stdin);
    // freopen("socdist1.out", "w", stdout);

    int n, m; cin >> n >> m;
    vector <vector<char>> rule(n, vector<char>(n, 'D'));
    for (int i = 0; i < n; ++i){
        string st;
        cin >> st;
        for (int j = 0; j < i; ++j)
            if (st[j] == 'W'){
                rule[i][j] = 'W';
                rule[j][i] = 'L';
            } else if (st[j] == 'L') {
                rule[j][i] = 'W';
                rule[i][j] = 'L';
            }
    }

    // for (int i = 0; i < n; ++i){
    //     for (int j = 0; j < n; ++j)
    //         cout << rule[i][j] << ' ';
    //     cout << "\n";
    // }

    while (m--){
        int a, b; cin >> a >> b;
        --a, --b;
        vector <bool> wins(n); // those we want to avoid
        wins[a] = 1, wins[b] = 1;
        for (int i = 0; i < n; ++i){
            wins[i] = wins[i] | (rule[a][i] == 'W' || rule[a][i] == 'D');
            wins[i] = wins[i] | (rule[b][i] == 'W' || rule[b][i] == 'D');
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i){
            // cout << wins[i] << ' ';
            cnt += wins[i];
        }
        // cout << "\n";
        cout << n * n - cnt * cnt << "\n";
    }


    return 0;
}