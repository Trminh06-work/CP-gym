// Link: https://usaco.org/index.php?page=viewproblem2&cpid=712

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);

    string st; cin >> st;
    vector <pair<int, int>> cows(26, {-1, -1});

    for (int i = 0; i < 52; ++i)
        if (cows[st[i] - 'A'].fi == -1)
            cows[st[i] - 'A'].fi = i;
        else
            cows[st[i] - 'A'].se = i;

    int ans = 0;
    for (int i = 0; i < 26; ++i)
        for (int j = i + 1; j < 26; ++j){
            if (cows[i].se < cows[j].fi || cows[i].fi > cows[j].se) continue;  // not intersect
            if (cows[i].fi > cows[j].fi && cows[i].se < cows[j].se) continue;  // in range j
            if (cows[i].fi < cows[j].fi && cows[i].se > cows[j].se) continue;  // cover j
            ++ans;
        }
    cout << ans;
    return 0;
}