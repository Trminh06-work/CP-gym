// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1445

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

    // freopen("herding.in", "r", stdin);
    // freopen("herding.out", "w", stdout);

    int n, f; cin >> n >> f;
    string st; cin >> st;
    map <string, int> valid_triplet;

    // for (int i = 0; i < n - 2; ++i){
    //     string subst = st.substr(i, 3);
    //     cout << subst << "\n";
    // }

    // Prepare all "subst" possibilities
    for (char ci = 'a'; ci <= 'z'; ++ci)
        for (char cj = 'a'; cj <= 'z'; ++cj)
            if (ci != cj)
                valid_triplet[string{ci, cj, cj}] = 0;

    // Prepare the valid triplets -> process one by one
    // Observe: if c_i c_j c_k is valid
    //          -> the next possibly valid is c_k ....
    //          -> no need to sanity check
    for (int i = 0; i < n - 2; ++i){
        string subst = st.substr(i, 3);
        if (subst[0] != subst[1] && subst[1] == subst[2])
            valid_triplet[subst]++;
    }

    set <string> ans;
    // a triplet "subst" is an answer iff valid_triplet[subst] >= f
    //  Or valid_triplet[subst] == f - 1 -> further check
    for (const auto& [subst, num]: valid_triplet){
        if (num < f - 1) continue; // unable to fix
        if (num >= f) {ans.insert(subst); continue;}

        // resolve num == f - 1 -> loop through the initial "st"
        for (int i = 0; i < n - 2; ++i){
            string sub = st.substr(i, 3);
            if (sub == subst) continue; // already counted -> skip

            // x c_j c_j and c_j == subst[1]
            if (sub[1] == sub[2] && sub[1] == subst[1]){
                // cout << subst << " : " << sub << "\n";
                // ensure x does not intersect with
                // the valid subst, i.e. c_i c_j x c_j c_j
                if (i < 1){
                    // impossible to intersect
                    ans.insert(subst);
                    // cout << subst << " Here\n";
                    break;
                }
                string pre_sub = st.substr(i - 1, 3);
                if (pre_sub == subst){
                    // no gain if we correct it -> skip
                    continue;
                } else {
                    if (i > 1){
                        string pre_sub = st.substr(i - 2, 3);
                        if (pre_sub == subst){
                            // no gain if we correct it -> skip
                            continue;
                        }
                    }
                    // does not intersect
                    ans.insert(subst);
                    // cout << subst << " Here2\n";
                    break;
                }
            }

            // c_i x c_j && c_i == subst[0] && c_j == subst[2] && x != c_j
            if (sub[1] != sub[2] && sub[0] == subst[0] && sub[2] == subst[2]){
                // cout << subst << ' ' << sub << " Here!\n";
                // ensure x does not intersect with
                // the valid subst, i.e. c_i c_j x c_j c_j
                // cout << subst << " : " << sub << "\n";
                if (i == n - 3){
                    // impossible to intersect
                    ans.insert(subst);
                    // cout << subst << " Here3\n";
                    break;
                }
                string suff_sub = st.substr(i + 1, 3);
                if (suff_sub == subst){
                    // no gain if we correct it -> skip
                    continue;
                } else {
                    // does not intersect
                    ans.insert(subst);
                    // cout << subst << ' ' << suff_sub << " Here4\n";
                    break;
                }
            }

            // c_i c_j x && c_i == subst[0] && c_j == subst[1]
            if (sub[0] == subst[0] && sub[1] == subst[1]){
                // ensure x does not intersect with
                // the valid subst, i.e. c_i c_j x c_j c_j
                // cout << subst << " : " << sub << "\n";
                if (i == n - 3){
                    // impossible to intersect
                    ans.insert(subst);
                    // cout << subst << " Here3\n";
                    break;
                }
                string suff_sub = st.substr(i + 2, 3);
                if (suff_sub == subst){
                    // no gain if we correct it -> skip
                    continue;
                } else {
                    // does not intersect
                    ans.insert(subst);
                    // cout << subst << ' ' << suff_sub << " Here4\n";
                    break;
                }
            }
        }
    }


    cout << ans.size() << "\n";
    for (auto& st: ans) cout << st << "\n";

    return 0;
}