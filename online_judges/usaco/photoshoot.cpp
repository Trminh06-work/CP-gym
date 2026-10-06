// Link:

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


    // freopen("factory.in", "r", stdin);
    // freopen("factory.out", "w", stdout);

    int n; cin >> n;
    string st; cin >> st;

    // Claims:
    // 1. N is even => always 4 possible pairs
    // HH, GG -> meaningless (reverse -> same order, diff location)
    // HG, GH -> potential
    // 2. prefix length is even => odd pos <-> even pos


    // Instead of reverting -> flip the pair
    // 0 -> 1, 1 -> 0, x -> x (1: GH, 0: HG, x: HH, GG)
    // Therefore, we can group the connected pairs as 1 pair
    // Ex: GHGHGH -> 111 -> 1

    // create a string accord. to the def. above
    string tmp = "";
    for (int i = 0; i < n;  i += 2)
        if (string{st[i], st[i + 1]} == "GH") tmp += '1';
        else if (string{st[i], st[i + 1]} == "HG") tmp += '0';
        else tmp += 'x';

    // group them
    string main_st = "";
    n = tmp.size();
    for (int i = 0; i < n;){
        main_st += tmp[i++];
        while (i < n && tmp[i] == tmp[i - 1]) ++i;
    }
    // cout << "\n";
    // cout << tmp << "\n" << main_st << "\n";

    // solve backward
    n = main_st.size();
    int ans = 0;
    for (int i = n - 1; i >= 0; --i){
        if (main_st[i] == 'x') continue; // skip
        int k = (main_st[i] == '1');
        if ((k + ans) % 2 == 1) ++ans;
    }
    cout << ans;

    return 0;
}