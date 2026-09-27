#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("gymnastics.in",  "r", stdin);
    freopen("gymnastics.out", "w", stdout);

    int n, k, a; cin >> k >> n;
    vector <vector<int>> ranks(k, vector <int> (n));
    for (int i = 0; i < k; ++i)
        for (int j = 0; j < n; ++j){
            cin >> a;
            ranks[i][a - 1] = j;
        }

    int ans = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (i != j){
                int sup = 0;
                for (auto& rank: ranks)
                    sup += (rank[i] < rank[j]);
                if (sup == k)
                    ans++;
            }
    cout << ans;
    return 0;
}