// Link: https://usaco.org/index.php?page=viewproblem2&cpid=893

// Note:
// only count the `yes` answers
// No 2 anmials sharing the same set of characterisitcs
// -> whatever is asked, we are left with two animals before getting the right answer

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("guess.in", "r", stdin);
    freopen("guess.out", "w", stdout);

    int n, k; cin >> n;
    string s;
    vector <vector<string>> characs(n);
    for (auto& chars: characs){
        cin >> s >> k;
        chars.resize(k);
        for (auto& ch: chars) cin >> ch;
    }

    int ans = 0;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j){
            int same_char = 0;
            for (string ch1: characs[i])
                for (string ch2: characs[j])
                    if (ch1 == ch2){
                        same_char++;
                        break;
                    }
            ans = max(ans, same_char + 1);
        }
    cout << ans;
    return 0;
}