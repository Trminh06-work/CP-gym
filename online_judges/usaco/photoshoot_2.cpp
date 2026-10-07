// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1204#

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


    freopen("hoofball.in", "r", stdin);
    freopen("hoofball.out", "w", stdout);

    int n; cin >> n;
    vector <int> a(n + 1);
    vector <int> cur_pos(n + 1);
    vector <int> desire_pos(n + 1);
    vector <bool> moved(n + 1);

    // Do not ask which cow is moved, but which cow is NOT moved
    // Any cow can be move left once to reach the desired location
    //      regardless of whether it's initially correct or not
    // Hence, a cow isn't moved across all operations are more important
    // => Counting problem

    for (int i = 1; i <= n; ++i){
        int v; cin >> v;
        cur_pos[i] = v;
        // cout << a[i] << ' ';
    }
    // cout << "\n";

    for (int i = 1; i <= n; ++i){
        int v; cin >> v;
        desire_pos[i] = v;
        // cout << v << ' ';
    }
    // cout << "\n";

    int ans = 0;
    int j = 1; // current cur_pos == desired_pos

    // go through all desired location
    for (int i = 1; i <= n; ++i){
        while (j <= n && moved[cur_pos[j]]) ++j;

        if (cur_pos[j] == desire_pos[i]) ++j;
        else {
            ++ans;
            moved[desire_pos[i]] = true;
        }
    }

    cout << ans;

    return 0;
}