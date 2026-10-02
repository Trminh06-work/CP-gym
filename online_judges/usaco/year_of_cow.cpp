// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1107

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("angry.in", "r", stdin);
    // freopen("angry.out", "w", stdout);

    int n; cin >> n;
    string st;

    map<string, int> zodiac = {
        {"Ox", 0}, {"Tiger", 1}, {"Rabbit", 2}, {"Dragon", 3}, {"Snake", 4},
        {"Horse", 5}, {"Goat", 6}, {"Monkey", 7}, {"Rooster", 8}, {"Dog", 9},
        {"Pig", 10}, {"Rat", 11}
    };

    map<string, pair<string, int>> cows;
    cows["Bessie"] = {"Ox", 0};

    while (n--){
        string prev_name, cur_name, cur_year;
        bool is_after = true;
        for (int i = 1; i <= 8; ++i){
            cin >> st;
            if (i == 1) cur_name = st;
            else if (i == 4) is_after = (st != "previous");
            else if (i == 5) cur_year = st;
            else if (i == 8) prev_name = st;
        }
        // year of the aforementioned cow
        int prev = zodiac[cows[prev_name].fi];
        int cur = zodiac[cur_year]; // year of the current cow
        int gap;
        if (is_after){ // 'cur_name' is after 'prev_name'
            gap = (cur - prev + 12) % 12;
            if (gap == 0) gap = 12;
            cows[cur_name] = {cur_year, cows[prev_name].se + gap};
        } else { // 'cur_name' is previous/before 'prev_name'
            gap = (prev - cur + 12) % 12;
            if (gap == 0) gap = 12;
            cows[cur_name] = {cur_year, cows[prev_name].se - gap};
        }
        // cout << cows[prev_name].fi << ' ' << cur_year << ' ';
        // cout << prev << ' ' << cur << ' ' << gap << ' ' << cows[cur_name].se << '\n';
    }

    // cout << '\n';
    cout << abs(cows["Elsie"].se);

    // cout << '\n';
    // for (const auto& [name, info]: cows)
    //     cout << name << ' ' << info.fi << ' ' << info.se << '\n';

    return 0;
}