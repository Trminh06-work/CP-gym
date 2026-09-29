// Link: https://usaco.org/index.php?page=viewproblem2&cpid=857

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second

set <int> res;
vector <vector<int>> bucket(2, vector<int>(10));
int sum[2] = {1000, 1000};
vector <vector<bool>> has_bucket(2, vector<bool>(10, true));

// Tuesday -> Friday : 0 -> 3
void solve(int day, int size){
    if (day == 4) {
        res.insert(sum[0]);
        return;
    }

    int d = (day % 2);

    // take all buckets in the current barns
    for (int i = 0; i < 10; ++i){
        if (!has_bucket[d][i]) continue;
        sum[d] -= bucket[d][i];
        sum[d ^ 1] += bucket[d][i];
        has_bucket[d][i] = false;

        solve(day + 1, bucket[d][i]);

        has_bucket[d][i] = true;
        sum[d] += bucket[d][i];
        sum[d ^ 1] -= bucket[d][i];
    }

    // return the bucket
    if (size > 0){
        sum[d] -= size;
        sum[d ^ 1] += size;

        solve(day + 1, 0);

        sum[d] += size;
        sum[d ^ 1] -= size;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("backforth.in", "r", stdin);
    freopen("backforth.out", "w", stdout);

    for (int&b: bucket[0]) cin >> b;
    for (int&b: bucket[1]) cin >> b;

    // day 1
    for (int i = 0; i < 10; ++i){
        sum[0] -= bucket[0][i];
        sum[1] += bucket[0][i];
        has_bucket[0][i] = false;
        solve(1, bucket[0][i]);
        has_bucket[0][i] = true;
        sum[0] += bucket[0][i];
        sum[1] -= bucket[0][i];
    }
    // for (auto& r: res) cout << r << ' ';
    cout << res.size();
    return 0;
}