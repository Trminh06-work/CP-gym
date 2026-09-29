// Link: https://codeforces.com/contest/863/problem/B

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("backforth.in", "r", stdin);
    // freopen("backforth.out", "w", stdout);

    int n; cin >> n;
    vector <int> w(2 * n);
    for (auto& v: w) cin >> v;

    sort(all(w));
    // for (auto& v: w) cout << v << ' '; cout << "\n";
    n <<= 1;

    int ans = 1e6;

    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j){
            int total = 0, k = 0;
            while (k < n){
                int a = k, b = k + 1;
                if (a == i || a == j) {
                    ++k; continue;
                }
                b += ((b == i) || (b == j));
                if (b >= n) break;
                total += abs(w[a] - w[b]);
                k = b + 1;

            }
            ans = min(ans, total);
        }

    cout << ans;

    return 0;
}