// Link: https://atcoder.jp/contests/abc202/tasks/abc202_c

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

    int n; cin >> n;
    vector <int> a(n), b(n), c(n);
    for (auto& v: a) cin >> v;
    for (auto& v: b) cin >> v;
    for (auto& v: c) cin >> v;

    // Solve the easier version
    // Think of C as an array of 1 -> n
    // Then, we are left with only A and B

    // Loop through B: count b_j occurrences
    // Loop through A: add the results

    // Generalise to arbitrary C
    // Loop through C: count b[c[j]] occurrences
    // Loop through A: add the results

    vector <int> cnt(n + 1);
    for (int i = 0; i < n; ++i)
        cnt[b[c[i] - 1]]++;

    ll ans = 0;
    for (int i = 0; i < n; ++i)
        ans += 1LL * cnt[a[i]];

    cout << ans;
    return 0;
}