// Link: https://usaco.org/index.php?page=viewproblem2&cpid=965

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);

    int n; cin >> n;
    cin.ignore();  // consume the newline
    vector <string> perm = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
    vector <pair<string, string>> constraints;
    for (int i = 0; i < n; ++i){
        string st; getline(cin, st);
        string name_1 = "", name_2 = "";

        for (auto& ch: st)
            if (ch != ' ')
                name_1 += ch;
            else
                break;

        reverse(st.begin(), st.end());
        for (auto& ch: st)
            if (ch != ' ')
                name_2 += ch;
            else
                break;
        reverse(name_2.begin(), name_2.end());
        constraints.push_back({name_1, name_2});
    }

    // for (auto& names: constraints)
    //     cout << names.fi << ' ' << names.se << '\n';
    // cout << '\n';

    sort(perm.begin(), perm.end());
    do {
        bool correct_perm = true;
        for (auto& names: constraints){
            int pos_1, pos_2;
            for (int pos = 0; pos < 8; ++pos){
                if (perm[pos] == names.fi) pos_1 = pos;
                if (perm[pos] == names.se) pos_2 = pos;
            }
            correct_perm &= (pos_1 == pos_2 + 1 || pos_1 == pos_2 - 1);
        }
        if (correct_perm) break;
    } while (next_permutation(perm.begin(), perm.end()));

    for (auto& name: perm) cout << name << '\n';
    return 0;
}