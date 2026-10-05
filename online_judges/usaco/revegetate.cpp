// Link: https://usaco.org/index.php?page=viewproblem2&cpid=916

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

    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);

    int n, m; cin >> n >> m;
    set <int> colors[4];
    vector <vector<int>> fields(n);

    for (int i = 1; i <= m; ++i){
        int a, b; cin >> a >> b;
        --a, --b;
        fields[a].push_back(i);
        fields[b].push_back(i);
    }

    // try color (grass type) : 1 -> 4
    // store each color, the set of cows
    // check if that color consists a list of that cow
    // if yes, move to the next color,
    // otherwise, that color is the correct choice
    for (int i = 0; i < n; ++i){
        for (int color = 0; color < 4; ++color){
            bool ok = true;
            for (int& cow: fields[i])
                ok &= (colors[color].count(cow) == 0);
            if (ok){
                for (int& cow: fields[i])
                    colors[color].insert(cow);
                cout << color + 1;
                break;
            }
        }
    }


    return 0;
}