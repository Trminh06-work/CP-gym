// Link: https://usaco.org/index.php?page=viewproblem2&cpid=915

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

    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);

    int a[3];
    for (int i = 0; i < 3; ++i) cin >> a[i];
    sort(a, a + 3);


    if (a[1] - a[0] == 1 && a[2] - a[1] == 1){
        cout << "0\n0";
        return 0;
    }

    // Minimum moves
    // [-|--||--] => 2
    // [-|--|-|--] => 1
    // [-|--|----|--] => 2
    if (a[1] - a[0] == 2 || a[2] - a[1] == 2)
        cout << 1 << "\n";
    else
        cout << 2 << "\n";


    // Maximum moves
    cout << max(a[1] - a[0], a[2] - a[1]) - 1;
    return 0;
}