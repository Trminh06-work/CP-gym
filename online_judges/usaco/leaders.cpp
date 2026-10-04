// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1275

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

    int n; cin >> n;
    string st; cin >> st;
    vector <int> e(n);
    for (auto& v: e) cin >> v;

    vector <int> suff[2];
    suff[0].push_back(0);
    suff[1].push_back(0);

    for (char& ch: st)
        if (ch == 'G'){
            suff[0].push_back(suff[0].back() + 1);
            suff[1].push_back(suff[1].back());
        } else {
            suff[1].push_back(suff[1].back() + 1);
            suff[0].push_back(suff[0].back());
        }
    // cout << "Suffix 1\n";
    // for (int i = 0; i <= n; ++i)
    //     cout << suff[0][i] << ' ';
    // cout << "\n";

    // cout << "Suffix 2\n";
    // for (int i = 0; i <= n; ++i)
    //     cout << suff[1][i] << ' ';
    // cout << "\n";



    // A leader must hold a list of its breed
    vector <bool> lead(n);
    for (int i = 0; i < n; ++i){
        if (st[i] == 'G') {
            int total = suff[0][e[i]] - suff[0][i];
            lead[i] = lead[i] | (total == suff[0].back());
        }
        else {
            int total = suff[1][e[i]] - suff[1][i];
            lead[i] = lead[i] | (total == suff[1].back());
        }
    }

    // cout << "\n";
    // cout << "LEAD\n";
    // for (int i = 0; i < n; ++i)
    //     cout << lead[i] << ' ';
    // cout << "\n";

    // If not, a leader must hold contain leader from other breed
    vector <int> another_lead[2];
    another_lead[0].push_back(0);   // Lead of G
    another_lead[1].push_back(0);   // Lead of H
    for (int i = 0; i < n; ++i)
        if (st[i] == 'G'){
            another_lead[0].push_back(another_lead[0].back() + lead[i]);
            another_lead[1].push_back(another_lead[1].back());
        } else {
            another_lead[1].push_back(another_lead[1].back() + lead[i]);
            another_lead[0].push_back(another_lead[0].back());
        }

    // cout << "Another lead G\n";
    // for (int i = 0; i <= n; ++i)
    //     cout << another_lead[0][i] << ' ';
    // cout << "\n";

    for (int i = 0; i < n; ++i){
        if (st[i] == 'G') {
            int total = another_lead[1][e[i]] - another_lead[1][i];
            // cout << i << " : " << e[i] << " " << total << "\n";
            lead[i] = lead[i] | total;
        } else {
            int total = another_lead[0][e[i]] - another_lead[0][i];
            // cout << i << " : "  << e[i] << " " << total << "\n";
            lead[i] = lead[i] | total;
        }
    }
    // cout << "LEAD\n";
    // for (int i = 0; i < n; ++i)
    //     cout << lead[i] << ' ';
    // cout << "\n";

    // Compute the answer
    int cnt_g = 0, cnt_h = 0;
    for (int i = 0; i < n; ++i)
        if (st[i] == 'G') cnt_g += lead[i];
        else cnt_h += lead[i];
    cout << cnt_g * cnt_h;
    return 0;
}