// Link: https://codeforces.com/contest/831/problem/C

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fi first
#define se second

const int maxVal = 8e6;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("herding.in", "r", stdin);
    // freopen("herding.out", "w", stdout);

    int k, n, minn = 0, maxx = 0; cin >> k >> n;
    vector <int> a(k), b(n);
    for (auto& v: a) cin >> v;
    for (auto& v: b) cin >> v;

    int sum = 0;
    set <int> suff;
    for (auto& v: a) {
        sum += v;
        suff.insert(sum);
    }

    // cout << maxVal * 2 + 3 << "\n";
    // Using map => TLE => take advantage of the small range and use counting vector
    vector <int> mp(maxVal * 2 + 3);
    for (auto& u: b)
        for (auto& v: suff){
            // cout << maxVal + u - v << ' ';
            mp[maxVal + u - v]++;
        }
    // cout << "\n";


    // for (auto& v: suff) cout << v << ' ';
    // cout << '\n';


    int ans = 0;
    for (auto& cnt: mp)
        ans += (cnt == n);
    cout << ans;

    return 0;
}