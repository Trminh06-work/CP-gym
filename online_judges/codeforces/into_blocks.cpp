// Link: https://codeforces.com/contest/1209/problem/G1

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fi first
#define se second

const int maxVal = 2e5;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("socdist1.in", "r", stdin);
    // freopen("socdist1.out", "w", stdout);

    int n, q; cin >> n >> q;
    vector <int> a(n);
    for (auto& v: a) cin >> v;

    set <int> s;
    vector <int> cnt(maxVal + 1);
    vector <int> l(maxVal + 1, maxVal + 1), r(maxVal + 1);
    for (int i = 0; i < n; ++i) {
        s.insert(a[i]);
        cnt[a[i]]++;
        l[a[i]] = min(l[a[i]], i);
        r[a[i]] = max(r[a[i]], i);
    }

    string st(n, '.');
    for (auto& v: s)
        if (l[v] != r[v])
            st[l[v]] = '(', st[r[v]] = ')';
    // cout << st << "\n";

    // for (auto& v: s)
    //     cout << v << " : " << cnt[v] << '\n';
    // cout << "\n";



    int ans = 0;
    stack <int> stk;
    for (int i = 0; i < n; ++i){
        if (st[i] == '.') continue;
        if (st[i] == '(')
            stk.push(i);
        else {
            int prev = stk.top();
            stk.pop();
            if (stk.size() == 0){
                // cout << i << ' ' << prev << "\n";
                int maxx = 0;
                for (int j = prev; j <= i; ++j)
                    maxx = max(maxx, cnt[a[j]]);
                ans += (i - prev + 1 - maxx);
            }
        }
    }
    cout << ans;

    return 0;
}