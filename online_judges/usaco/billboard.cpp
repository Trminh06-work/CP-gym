// Link: https://usaco.org/index.php?page=viewproblem2&cpid=759

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fi first
#define se second

struct Rect{
    int x0, y0, x1, y1;
    void read() {cin >> x0 >> y0 >> x1 >> y1;}
    int area() {return (y1 - y0) * (x1 - x0);}
};

int intersect(Rect u, Rect v){
    // Let (x, y) in the intersection, then:
    // max(u.x0, v.x0) < x < min(u.x1, v.x1)
    // max(u.y0, v.y0) < y < min(u.y1, v.y1)
    int x0 = max(u.x0, v.x0);
    int x1 = min(u.x1, v.x1);
    int y0 = max(u.y0, v.y0);
    int y1 = min(u.y1, v.y1);

    int overlapX = max(0, x1 - x0);
    int overlapY = max(0, y1 - y0);

    return overlapX * overlapY;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);

    Rect a, b, t;
    a.read(); b.read(); t.read();

    // lower-left and upper-right
    cout << a.area() + b.area() - intersect(a, t) - intersect(b, t);
    return 0;
}