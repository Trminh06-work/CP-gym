// Link: https://usaco.org/index.php?page=viewproblem2&cpid=617#

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second


int try_cut(vector <pair<int, int>>& pts, int& a, int& b){
    // Verify fences do not cross any cows
    for (auto& pt: pts)
        if (pt.fi == a || pt.se == b)
            return pts.size();

    // Compute the angles -> determine the quadrants
    vector <int> quad(4);
    for (auto&pt: pts){
        int new_x = pt.fi - a, new_y = pt.se - b;
        // atan2(y, x) = arctan(y/x)
        double angle_rad = atan2(new_y, new_x);    // -> [-pi, pi]
        double angle_deg = angle_rad * 180 / M_PI; // -> [-180, 180]
        angle_deg += 180;                          // -> [0, 360]
        if (angle_deg <= 90)
            quad[0]++;
        else if (angle_deg <= 180)
            quad[1]++;
        else if (angle_deg <= 270)
            quad[2]++;
        else
            quad[3]++;
    }

    int maxx = 0;
    for (int q = 0; q < 4; ++q)
        maxx = max(maxx, quad[q]);
    return maxx;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);

    int n, b;
    cin >> n >> b;
    vector <pair<int, int>> pts(n);
    for (auto& pt: pts) cin >> pt.fi >> pt.se;
    int ans = n;

    if (n < 2) {cout << 1; exit(0);}

    sort(pts.begin(), pts.end());

    int d[2] = {1, -1};

    // try every two points, using each as the horizontal or vertical cut
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j){
            for (int ii = 0; ii < 2; ++ii)
                for (int jj = 0; jj < 2; ++jj){
                    int cx = pts[i].fi + d[ii];
                    int cy = pts[j].se + d[jj];
                    ans = min(ans, try_cut(pts, cx, cy));
                }

            for (int ii = 0; ii < 2; ++ii)
                for (int jj = 0; jj < 2; ++jj){
                    int cx = pts[i].se + d[ii];
                    int cy = pts[j].fi + d[jj];
                    ans = min(ans, try_cut(pts, cx, cy));
                }
        }
    cout << ans;
    return 0;
}