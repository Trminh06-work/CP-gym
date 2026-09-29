// Link: https://cses.fi/problemset/task/1070/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define all(x) x.begin(), x.end()


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("backforth.in", "r", stdin);
    // freopen("backforth.out", "w", stdout);

    int n; cin >> n;
    if (n == 1){
        cout << n;
        exit(0);
    }
    if (n == 4){
        cout << "2 4 1 3";
        exit(0);
    }
    if (n < 4){
        cout << "NO SOLUTION";
        exit(0);
    }
    
    vector <int> ans;
    ans.push_back(1);
    int i = 3, j = 2;
    for (; i <= n && j <= n;){
        if (i < j){
            if (abs(i - ans.back()) == 1){
                ans.push_back(j);
                j += 2;
            } else {
                ans.push_back(i);
                i += 2;
            }
        } else { // j < i
            if (abs(j - ans.back()) == 1){
                ans.push_back(i);
                i += 2;
            } else {
                ans.push_back(j);
                j += 2;
            }
        }
    }
    for (; i <= n; i += 2) ans.push_back(i);
    for (; j <= n; j += 2) ans.push_back(j);

    // the last 4 may violate the rules
    vector <int> perm;
    for (int i = n - 2; i < n; ++i)
        if (abs(ans[i] - ans[i - 1]) == 1){
            for (int j = 0; j < 4; ++j) {
                perm.push_back(ans.back());
                ans.pop_back();
            }
            sort(all(perm));
            do{
                bool exit = true;
                for (int j = 1; j < perm.size(); ++j)
                    if (abs(perm[j] - perm[j - 1]) == 1) exit = false;
                if (exit) break;
            } while(next_permutation(all(perm)));
            for (int j = 0; j < 4; ++j)
                ans.push_back(perm[j]);
            break;
        }

    // all good
    for (auto&v: ans) cout << v << " ";
    return 0;
}