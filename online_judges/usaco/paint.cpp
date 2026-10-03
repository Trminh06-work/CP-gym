// Link: https://usaco.org/index.php?page=viewproblem2&cpid=567

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

    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);

    int a, b, c, d; cin >> a >> b >> c >> d;
    // separately check if Bessie's paintings do not overlap
    // with the designated interval
    if (c > b || d < a)
        cout << d - c + b - a;
    else
        cout << abs(max(b, d) - min(a, c));

    return 0;
}