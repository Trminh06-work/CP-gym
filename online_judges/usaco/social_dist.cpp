// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1035

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

    freopen("socdist1.in", "r", stdin);
    freopen("socdist1.out", "w", stdout);

    int n; cin >> n;
    string st; cin >> st;

    int first_cow = 0, last_cow = 0;
    for (int i = 0; i < n; ++i)
        if (st[i] == '1'){
            first_cow = i;
            break;
        }
    for (int i = n - 1; i >= 0; --i)
        if (st[i] == '1'){
            last_cow = i;
            break;
        }


    int ans = 0;
    // 3 cases:

    // 2 cows at both ends (if possible)
    if (st[0] == '0' && st[n - 1] == '0'){
        st[0] = '1', st[n - 1] = '1';
        int prev = 0, dist = n + 1;
        for (int i = 1; i < n; ++i) // skip the 1st cow
        if (st[i] == '1'){
            dist = min(dist, i - prev - 1);
            prev = i;
        }
        ans = max(ans, dist);
        st[0] = '0', st[n - 1] = '0';
    }
    // cout << ans << " Case 1\n";

    // 1 cow at either ends (if possible), 1 cow freely
    if (st[0] == '0' || st[n - 1] == '0'){
        if (st[0] == '0'){
            vector <int> dist;
            int prev = 0; // 1st cow allocation
            for (int i = 1; i <= last_cow; ++i)
                if (st[i] == '1'){
                    dist.push_back(i - prev - 1);
                    prev = i;
                }
            if (dist.size() >= 1){
                // at least 1 cow in barn
                // otherwise, back to the 1st case
                sort(all(dist));
                int maxx = dist.back();
                dist.pop_back();
                maxx = (maxx + 1) / 2 - 1; // 1st cow allocation
                dist.push_back(maxx);
                sort(all(dist));
                ans = max(ans, dist.front());
            }
        }
        if (st[n - 1] == '0'){
            vector <int> dist;
            int prev = first_cow; // 1st cow allocation
            st[n - 1] = '1';
            for (int i = first_cow + 1; i < n; ++i)
                if (st[i] == '1'){
                    dist.push_back(i - prev - 1);
                    prev = i;
                }
            st[n - 1] = '0';
            if (dist.size() >= 1){
                // at least 1 cow in barn
                // otherwise, back to the 1st case
                sort(all(dist));
                int maxx = dist.back();
                dist.pop_back();
                maxx = (maxx + 1) / 2 - 1; // 2nd cow allocation
                dist.push_back(maxx);
                sort(all(dist));
                ans = max(ans, dist.front());
            }
        }
    }
    // cout << ans << " Case 2\n";

    // no cows at both ends
    vector <int> origin_dist;
    int prev = first_cow;
    for (int i = first_cow + 1; i <= last_cow; ++i)
        if (st[i] == '1'){
            origin_dist.push_back(i - prev - 1);
            prev = i;
        }
        // at least two cows in barn
        // otherwise, back to the 1st case
    if (origin_dist.size() > 0){
        sort(all(origin_dist));
        // 2 smaller cases:
        // 2 cows in 1 interval
        vector <int> dist = origin_dist;
        int maxx = dist.back();
        // cout << maxx / 4 << '\n';
        if (maxx > 4) ans = max(ans, min(dist.front(), (maxx - 2) / 3));

        // 2 cows in 2 intervals
        dist = origin_dist;
        // for (auto &v: dist) cout << v << ' ';
        // cout << "\n";
        for (int t = 0; t < 2; ++t){
            maxx = dist.back();
            dist.pop_back();
            // for (auto &v: dist) cout << v << ' ';
            // cout << " Before\n";
            maxx = (maxx + 1) / 2 - 1; // cow allocation
            // cout << maxx << " maxx ";
            dist.push_back(maxx);
            sort(all(dist));
            // for (auto &v: dist) cout << v << ' ';
            // cout << " After\n";
        }

        sort(all(dist));
        ans = max(ans, dist.front());
    }
    // cout << ans << " Case 3\n";

    cout << ans + 1;


    return 0;
}