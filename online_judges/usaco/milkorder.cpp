// Link: https://usaco.org/index.php?page=viewproblem2&cpid=832

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fi first
#define se second

int n, m, k;
vector <int> cow;

bool solve(vector <int> origin_pos, vector <int>& order){
    int j = 0;
    vector <int> tmp_order;
    vector <int> pos = origin_pos;
    for (auto& v: order){
        if (cow[v - 1] == -1){
            // guess the place
            while (j < n && pos[j] != 0) ++j;
            pos[j] = v;
            tmp_order.push_back(j);
        } else{
            j = cow[v - 1]; // should take the current place
            tmp_order.push_back(cow[v - 1]);
        }
    }

    for (int i = 1; i < tmp_order.size(); ++i)
        if (tmp_order[i] < tmp_order[i - 1])
            return false;

    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);

    cin >> n >> m >> k;
    vector <int> order(m);
    for (auto& v: order) cin >> v;
    vector <int> pos(n);
    cow.resize(n, -1);

    while (k--){
        int c, p; cin >> c >> p;
        pos[p - 1] = c;
        cow[c - 1] = p - 1;
    }

    // in case it is already arranged
    if (cow[0] != -1){
        cout << cow[0] + 1;
        return 0;
    }

    // for (int i = 0; i < n; ++i)
    //     cout << pos[i] << ' ';
    // cout << "\n";

    // Test all possible places of cow1
    // Stop when valid
    for (int cow1 = 0; cow1 < n; ++cow1){
        if (pos[cow1]) continue; // occupied
        // cout << cow1 << " :\n";
        pos[cow1] = 1; // assume
        cow[0] = cow1;
        if (solve(pos, order)){
            cout << cow1 + 1;
            return 0;
        }
        pos[cow1] = 0;
        cow[0] = -1;
    }

    return 0;
}