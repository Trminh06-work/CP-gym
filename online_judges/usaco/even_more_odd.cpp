// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1084

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

    // freopen("cowtip.in", "r", stdin);
    // freopen("cowtip.out", "w", stdout);

    int n; cin >> n;
    int num_odd = 0, num_even = 0;

    // odd + odd   = even
    // odd + even  = odd
    //      => k * odd = odd  (k % 2 = 1)
    //      => k * odd = even (k % 2 = 0)
    // even + even = even

    int k;
    while (n--){
        cin >> k;
        if (k & 1) num_odd++;
        else num_even++;
    }

    k = min(num_even, num_odd);
    num_even -= k;
    num_odd -= k;
    // always end in odd, since we start with even - ...
    // the same first `k` groups (odd and even)
    if (num_odd == 0)
        // num_even > num_odd => can't form another odd group
        if (num_even == num_odd)
            cout << 2 * k;
        else
            cout << 2 * k + 1;
    else {
        // cout << k << ' ' << num_odd << ' ';
        // num_even < num_odd => possibly form odd and even groups

        // a + 2b = num_odd : 2 3 5 6  8  9  11 12 ...
        // 3a + 2b = num_odd: 2 5 7 10 12 15 17 20 ...
        // valid iff a <= b
        int maxx = 0;
        // a + 2b
        // cout << num_odd << '\n';
        if (num_odd == 1){
            cout << 2 * k - 1 << "\n";
            return 0;
        }
        for (int i = int(num_odd / 2); i >= 0; --i){
            if (i + 2 * i == num_odd) maxx = max(maxx, 2 * i);
            // special case, n = 10, 1 1 1 1 1 1 1 1 1 1 1
            if (i + 2 * i + 4 == num_odd) maxx = max(maxx, 2 * i + 1);
            if (i - 1 + 2 * i == num_odd) maxx = max(maxx, 2 * i - 1);
            if (i + 2 * (i + 1) == num_odd) maxx = max(maxx, 2 * i + 1);
            // cout << i << ' ' << maxx << "\n";
        }
        // cout << maxx << "\n";

        // 3a + 2b
        for (int i = int(num_odd / 3); i >= 0; --i){
            if (3 * i + 2 * i == num_odd) maxx = max(maxx, 2 * i);
            if (3 * (i - 1) + 2 * i == num_odd) maxx = max(maxx, 2 * i - 1);
            if (3 * i + 2 * (i + 1) == num_odd) maxx = max(maxx, 2 * i + 1);
        }
        // cout << k << ' ' << maxx;
        // cout << "\n";
        cout << 2 * k + maxx;
    }

    return 0;
}