// Link: https://codeforces.com/problemset/problem/581/D

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()

int ans = -1;
string res = "";


bool solve(vector <pair<int, int>>& origin){
    vector <pair<char, pair<int, int>>> logos;
    for (int i = 0; i < 3; ++i){
        if (i == 0) logos.push_back({'A', origin[i]});
        if (i == 1) logos.push_back({'B', origin[i]});
        if (i == 2) logos.push_back({'C', origin[i]});
    }

    // [0][1][2]
    if (logos[0].se.se == logos[1].se.se && logos[1].se.se == logos[2].se.se)
        if (logos[0].se.fi + logos[1].se.fi + logos[2].se.fi == logos[2].se.se){
            ans = logos[0].se.se;
            for (int i = 0; i < logos[0].se.se; ++i){
                for (int j = 0; j < logos[0].se.fi; ++j) res += logos[0].fi;
                for (int j = 0; j < logos[1].se.fi; ++j) res += logos[1].fi;
                for (int j = 0; j < logos[2].se.fi; ++j) res += logos[2].fi;
                res += '\n';
            }
            return true;
        }

    // [0]
    // [1]
    // [2]
    if (logos[0].se.fi == logos[1].se.fi && logos[1].se.fi == logos[2].se.fi)
        if (logos[0].se.se + logos[1].se.se + logos[2].se.se == logos[2].se.fi){
            ans = logos[0].se.fi;
            for (int i = 0; i < logos[0].se.se; ++i){
                for (int j = 0; j < logos[0].se.fi; ++j) res += logos[0].fi;
                res += '\n';
            }
            for (int i = 0; i < logos[1].se.se; ++i){
                for (int j = 0; j < logos[1].se.fi; ++j) res += logos[1].fi;
                res += '\n';
            }
            for (int i = 0; i < logos[2].se.se; ++i){
                for (int j = 0; j < logos[2].se.fi; ++j) res += logos[2].fi;
                res += '\n';
            }
            return true;
        }


    // [0][1]
    // [  2 ]
    // permute
    for (int perm = 2; perm >= 0; --perm){
        swap(logos[2], logos[perm]);
        if (logos[0].se.se == logos[1].se.se
            && logos[0].se.se + logos[2].se.se == logos[0].se.fi + logos[1].se.fi
            && logos[2].se.fi == logos[0].se.fi + logos[1].se.fi
        ){
            ans = logos[2].se.fi;
            for (int i = 0; i < logos[0].se.se; ++i){
                for (int j = 0; j < logos[0].se.fi; ++j) res += logos[0].fi;
                for (int j = 0; j < logos[1].se.fi; ++j) res += logos[1].fi;
                res += '\n';
            }
            for (int i = 0; i < logos[2].se.se; ++i){
                for (int j = 0; j < logos[2].se.fi; ++j) res += logos[2].fi;
                res += '\n';
            }
            return true;
        }
    }

    // [0][2
    // [1] 2]
    for (int perm = 2; perm >= 0; --perm){
        swap(logos[2], logos[perm]);
        if (logos[0].se.fi == logos[1].se.fi
            && logos[0].se.fi + logos[2].se.fi == logos[0].se.se + logos[1].se.se
            && logos[2].se.se == logos[0].se.se + logos[1].se.se
        ) {
            ans = logos[2].se.se;
            for (int i = 0; i < logos[0].se.se; ++i){
                for (int j = 0; j < logos[0].se.fi; ++j) res += logos[0].fi;
                for (int j = 0; j < logos[2].se.fi; ++j) res += logos[2].fi;
                res += '\n';
            }
            for (int i = 0; i < logos[1].se.se; ++i){
                for (int j = 0; j < logos[1].se.fi; ++j) res += logos[1].fi;
                for (int j = 0; j < logos[2].se.fi; ++j) res += logos[2].fi;
                res += '\n';
            }
            return true;
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("backforth.in", "r", stdin);
    // freopen("backforth.out", "w", stdout);

    vector <pair<int, int>> logos(3);
    for (auto& it: logos) cin >> it.fi >> it.se;

    for (int i = 0; i < (1 << 3); ++i){
        for (int j = 0; j < 3; ++j) // try rotation
            if (i & (1 << j))
                swap(logos[j].fi, logos[j].se);
        if (solve(logos)) break;
        for (int j = 0; j < 3; ++j) // return to original state
            if (i & (1 << j))
                swap(logos[j].fi, logos[j].se);

    }

    cout << ans << "\n";
    if (ans != -1) cout << res;

    return 0;
}