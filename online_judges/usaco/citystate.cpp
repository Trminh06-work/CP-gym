// Link: https://usaco.org/index.php?page=viewproblem2&cpid=667

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

    freopen("citystate.in", "r", stdin);
    freopen("citystate.out", "w", stdout);

    int n; cin >> n;
    map<string, multiset<string>> mp;

    string city, state;
    while (n--){
        cin >> city >> state;
        mp[state].insert(city.substr(0, 2));
    }
    
    // for (const auto& [state, cities]: mp){
    //     cout << state << ": ";
    //     for (auto& city: cities) cout << city << ' ';
    //     cout << '\n';
    // }
    // cout << '\n';

    int ans = 0;
    for (auto& [state, cities]: mp){
        // cout << "STATE: " << state << "\n";
        for (auto it = mp[state].begin(); it != mp[state].end();){
            if (*it == state) {++it; continue;}
            string corr_state = *it; // derived state
            auto jt = mp.find(corr_state);  // check derived state exists?
            // if (jt != mp.end()){
            //     cout << corr_state << ": ";
            //     for (auto& v: jt->second) cout << v << ' ';
            // cout << '\n';}
            if (jt != mp.end() && jt->second.count(state) > 0){
                ans += jt->second.count(state);
                it = mp[state].erase(it);
            } else ++it;
        }
        // for (const auto& [state, cities]: mp){
        //     cout << state << ": ";
        //     for (auto& city: cities) cout << city << ' ';
        //     cout << "\n";
        // }
        // cout << '\n';
    }
    cout << ans;

    return 0;
}