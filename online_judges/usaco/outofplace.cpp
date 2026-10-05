// Link: https://usaco.org/index.php?page=viewproblem2&cpid=785

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fi first
#define se second

int n;

int solve(int pos, vector <int> a){
    // Drop edge cases
    if (pos == 0 && a[0] < a[1])
        return n;
    if (pos == n - 1 && a[n - 1] >= a[n - 2])
        return n;

    // Remember the duplicate values
    bool is_taller = false;
    int ans = 0;
    // since the edge case is dropped, pos = 0 => is_taller = true
    if (pos == 0 || a[pos] > a[pos - 1]) is_taller = true;

    // cout << pos << ", " << a[pos] << " : ";
    if (is_taller){
        for (int i = pos, j = pos; i < n - 1;){
            if (a[i + 1] < a[j]){
                ++i, ++ans;
                while (i < n - 1 && a[i + 1] == a[i]) ++i;
                swap(a[j], a[i]);
                j = i;
            } else
                break;
        }
    } else {
        for (int i = pos, j = pos; i > 0;){
            // cout << i << " " << j << "\n";
            if (a[i - 1] > a[j]){
                --i, ++ans;
                while (i > 0 && a[i - 1] == a[i]) --i;
                swap(a[j], a[i]);
                j = i;
                // for (int i = 0; i < n; ++i)
                //     cout << a[i] << " ";
                // cout << "\n";
            } else
                break;
        }
    }

    // for (int i = 0; i < n; ++i)
    //     cout << a[i] << " ";
    // cout << "\n";

    // Verify if the new array is correct
    for (int i = 1; i < n; ++i)
        if (a[i] < a[i - 1])
            return n;

    // cout << ans << "\n";
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);

    cin >> n;
    vector <int> a(n);
    for (auto& v: a) cin >> v;

    // Bessie can be either taller or shorter
    int ans = n;
    for (int pos = 0; pos < n; ++pos)
        ans = min(ans, solve(pos, a));
    cout << ans;

    return 0;
}