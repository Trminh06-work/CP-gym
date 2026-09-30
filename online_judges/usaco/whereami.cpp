// Link: https://usaco.org/index.php?page=viewproblem2&cpid=964

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);

    int n; cin >> n;
    string st; cin >> st;

    int k = 1;
    for (; k <= n; ++k){
        set <string> seq;
        for (int i = 0; i <= n - k; ++i){
            string tmp = "";
            for (int j = i; j < i + k; ++j)
                tmp += st[j];
            if (seq.count(tmp) == 0)
                seq.insert(tmp);
            else
                break;
        }
        if (seq.size() == n - k + 1)
            break;
    }
    cout << k;

    return 0;
}