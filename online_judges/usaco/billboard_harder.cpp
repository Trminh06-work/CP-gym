// Link: https://usaco.org/index.php?page=viewproblem2&cpid=783

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

    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);

    int bl_ax, bl_ay, bl_bx, bl_by;
    int tr_ax, tr_ay, tr_bx, tr_by;
    cin >> bl_ax >> bl_ay >> tr_ax >> tr_ay;
    cin >> bl_bx >> bl_by >> tr_bx >> tr_by;

    int all = abs(tr_ax - bl_ax) * abs(tr_ay - bl_ay);

    // cover all -> 0
    if (bl_bx <= bl_ax && bl_by <= bl_ay && tr_bx >= tr_ax && tr_by >= tr_ay){
        cout << 0;
        return 0;
    }

    // no intersect -> all
    if (bl_ax >= tr_bx || bl_ay >= tr_by || tr_ax <= bl_bx || tr_ay <= bl_by){
        cout << all;
        return 0;
    }

    int length = min(tr_ax, tr_bx) - max(bl_ax, bl_bx);
    int width = min(tr_ay, tr_by) - max(bl_ay, bl_by);
    int intersect = max(0, abs(length * width));

    // wider than dx AND not in between dy
    if (bl_bx <= bl_ax && tr_bx >= tr_ax){
        if (tr_by <= tr_ay && bl_by >= bl_ay){
            cout << all;
            return 0;
        }
        cout << all - intersect;
        return 0;
    }
    
    // wider than dy AND not in between dx
    if (bl_by <= bl_ay && tr_by >= tr_ay){
        if (tr_bx <= tr_ax && bl_bx >= bl_ax){
            cout << all;
            return 0;
        }
        cout << all - intersect;
        return 0;
    }
    

    // intersect corner -> all
    cout << all;
    return 0;
}