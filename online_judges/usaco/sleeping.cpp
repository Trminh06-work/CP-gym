// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1203

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

    int t; cin >> t;
    while (t--){
        int maxx = 0;
        int n; cin >> n;
        vector <int> a(n + 1);
        a.push_back(0);
        for (int i = 1; i <= n; ++i){
            cin >> a[i];
            maxx = max(maxx, a[i]); // cannot decrease the cumulation -> start from max a_i
            a[i] += a[i - 1];
        }

        // Key: \sum_i a_i <= 10^6 and \sum_j t_j <= 10^5 => overall around O(10^7)
        int ans = n + 3;
        for (int c = maxx; c <= a[n]; ++c){
            int num_op = 0;
            int i = 0;
            while (i <= n){
                int j = i + 1;
                while (j <= n && a[j] < a[i] + c) ++j, num_op++;
                if (j > n || a[j] != a[i] + c) break;
                i = j;
            }
            if (i >= n) {
                ans = min(ans, num_op);
                break;  // we starts from the `maxx` -> found? -> the answer
                        // cuz higher `c` will require more operations
            }
        }

        cout << ans << "\n";

    }
    
    return 0;
}