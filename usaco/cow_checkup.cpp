// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1469

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("balancing.in", "r", stdin);
    // freopen("balancing.out", "w", stdout);

    int n; cin >> n;
    vector <int> a(n), b(n);
    for (auto& v: a) cin >> v;
    for (auto& v: b) cin >> v;

    vector <int> suff(n + 1);

    // count the similar and construct suffix array (original order)
    for (int i = 1; i <= n; ++i) suff[i] = (a[i - 1] == b[i - 1]) + suff[i - 1];


    // for (int i = 0; i <= n; ++i)
    //     cout << suff[i] << " ";
    // cout << '\n';
    // cout << "\n\n";

    // construct answers 0 -> n
    // Observe: start with [l,l + 1,...,r - 1, r] -> reverse [r,r-1,...,l+1,l]
    // Next (l-1, r+1) -> [l-1, l,l + 1,...,r - 1, r, r+1] -> reverse [r+1,r,r-1,...,l+1,l,l-1]
    // everytime, we only need to check the two endpoints.

    // looping all segments for [l == r] and [l == r - 1] -> O(n)
    // for each expanded segment -> O(n)
    // => O(n^2)

    vector <int> ans(n + 1);

    // [l == r]
    for (int i = 1; i <= n; ++i){
        int cnt = (a[i - 1] == b[i - 1]);
        for (int l = i, r = i; l > 0 && r <= n; --l, ++r){
            if (l == r) {
                // cout << i << ' ' << cnt << '\n';
                ans[suff[n]]++;
                continue;
            }
            int seg_1 = suff[l - 1] - suff[0];       // left untouched segment
            cnt += (a[l - 1] == b[r - 1]) + (a[r - 1] == b[l - 1]);
            int seg_2 = suff[n] - suff[r];           // right untouched segment
            // cout << i << ' ' << l << " " << r << " " << cnt << ' ' << seg_1 << ' ' << seg_2 << '\n';
            ans[cnt + seg_1 + seg_2]++;
        }

        cnt = 0;
        for (int l = i, r = i + 1; l > 0 && r <= n; --l, ++r){
            int seg_1 = suff[l - 1] - suff[0];       // left untouched segment
            cnt += (a[l - 1] == b[r - 1]) + (a[r - 1] == b[l - 1]);
            int seg_2 = suff[n] - suff[r];           // right untouched segment
            ans[cnt + seg_1 + seg_2]++;
        }

    }

    for (auto& res: ans) cout << res << '\n';
    return 0;
}