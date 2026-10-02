// Link: https://usaco.org/index.php?page=viewproblem2&cpid=687

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

    freopen("notlast.in", "r", stdin);
    freopen("notlast.out", "w", stdout);

    map <string, int> cows;
    string cow[7] = {"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};
    for (int i = 0; i < 7; ++i)
        cows[cow[i]] = 0;

    int n; cin >> n;
    string st; int k;
    while (n--){
        cin >> st >> k;
        cows[st] += k;
    }

    vector <pair<int, string>> list;
    for (const auto& [name, milk]: cows) list.push_back({milk, name});
    sort(rall(list));
    // for (auto& v: list) cout << v.fi << ' ' << v.se << '\n';
    // cout << '\n';

    pair<int, string> minn = list.back();
    list.pop_back();
    while (!list.empty() && list.back().fi == minn.fi) list.pop_back();

    if (!list.empty()) minn = list.back();

    while (!list.empty()){
        int cnt = 0;
        if (!list.empty() && list.back().fi == minn.fi){
            while (!list.empty() && list.back().fi == minn.fi) {
                list.pop_back();
                ++cnt;
            }
            // cout << minn.fi << ' ' << minn.se << ' ' << cnt << ' ' << list.empty() << '\n';
            if (cnt > 1){
                if (!list.empty()) {
                    minn = list.back();
                    list.pop_back();
                }
            } else{
                list.push_back(minn);
                break;
            }
        } else
            break;
    }
    // cout << '\n';
    // for (auto& v: list) cout << v.fi << ' ' << v.se << '\n';
    if (list.empty()) cout << "Tie";
    else cout << list.back().se;

    return 0;
}