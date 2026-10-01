// Link: https://usaco.org/index.php?page=viewproblem2&cpid=592

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

    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);

    int n; cin >> n;
    vector <int> x(n);
    for (int& v: x) cin >> v;

    int ans = 1;
    sort(all(x));
    // for (int& v: x) cout << v << " ";
    // cout << "\n";
    for (int i = 0; i < n; ++i){
        int total = 1;

        // go to the left
        int t = 1, j = i - 1;
        // check the current explosion
        while (j >= 0 && x[j] >= x[j + 1] - t){
            int k = j;
            while (k >= 0 && x[k] >= x[j + 1] - t) {
                ++total;
                --k;
            }
            ++t;
            j = k;
        }
        // cout << i << ' ' << total << ' ';

        // go to the right
        t = 1, j = i + 1;
        // check the current explosion
        while (j < n && x[j] <= x[j - 1] + t){
            // explode everything -> take the final
            // cout << i << ' ' << j << ' ' << x[j] << ' ' << x[j - 1] << ' ' <<  t << "\n";
            int k = j;
            while (k < n && x[k] <= x[j - 1] + t) {
                total++;
                ++k;
            }
            ++t;
            j = k;
            // cout << i << ' ' << j << ' ' << x[j] << ' ' << x[j - 1] << ' ' <<  t << "\n";
        }
        // cout << '\n';
        // cout << total << "\n";
        ans = max(ans, total);
    }

    cout << ans;
    return 0;
}