// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1276

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

    int n, m; cin >> n >> m;
    int ans = 0;
    vector <tuple<int, int, int>> cows(n);
    vector <tuple<int, int, int, int>> ac(m);
    for (auto& cow: cows){
        int s, t, c;
        cin >> s >> t >> c;
        cow = make_tuple(s, t, c);
    }
    for (auto& aic: ac){
        int a, b, p, m;
        cin >> a >> b >> p >> m;
        aic = make_tuple(a, b, p, m);
        ans += m;
    }


    for (int i = 0; i < (1 << m); ++i){
        vector <int> stall(103);
        int sum = 0;
        // turn on ac and compute the cost
        for (int j = 0; j < m; ++j)
            if (i & (1 << j)){
                int a = get<0>(ac[j]), b = get<1>(ac[j]); // get the range
                for (int k = a; k <= b; ++k) stall[k] += get<2>(ac[j]);
                sum += get<3>(ac[j]);
            }

        // verify cows' satisfaction
        for (int j = 0; j < n; ++j){
            int s = get<0>(cows[j]), t = get<1>(cows[j]), c = get<2>(cows[j]);
            for (int k = s; k <= t; ++k)
                if (stall[k] < c){
                    sum = 1e9;
                    break;
                }
        }
        ans = min(ans, sum);
    }

    cout << ans;

    return 0;
}