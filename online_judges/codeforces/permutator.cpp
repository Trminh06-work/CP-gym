// Link: https://codeforces.com/gym/104520/problem/H

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second

int n;

void trick(vector <ll> &a){
    // Observe:
    //
    // n = 2: 2 2
    // n = 4: 4 6 6 4
    // n = 6: 6 10 12 12 10 6
    // n = 8: 8 14 18 20 20 18 14 8
    //
    // n = 1: 1
    // n = 3: 3 4 3
    // n = 5: 5 8 9 8 5
    // n = 7: 7 12 15 16 15 12 7
    // n = 11: 11 20 27 32 35 36 35 32 27 20 11
    //
    //
    if (n & 1){
        ll occur = n;
        for (int i = 0; i < n / 2; ++i){
            a[i] *= 1LL * occur;
            occur += 1LL * (n / 2 - i) * 2 - 1;
        }
        a[(int)(n / 2)] *= 1LL * occur;
        for (int i = n / 2 + 1; i < n; ++i){
            occur -= (i - n / 2) * 2 - 1;
            a[i] *= 1LL * occur;
        }
    } else {
        ll occur = n;
        for (int i = 0; i < n / 2; ++i){
            a[i] *= 1LL * occur;
            occur += (n / 2 - i - 1) * 2;
        }
        for (int i = n / 2; i < n; ++i){
            occur -= (i - n / 2) * 2;
            a[i] *= 1LL * occur;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("angry.in", "r", stdin);
    // freopen("angry.out", "w", stdout);

    cin >> n;
    vector <ll> a(n), b(n);
    for (auto& v: a) cin >> v;
    for (auto& v: b) cin >> v;


    // a is fixed -> freely permute to get the minimum answer
    // for every subarray [i,j], k in [i,j], a[k]*b[j]
    //      => \sum_{k in [i, j]} a[k]*b[j] = (j - i + 1) * a[k] * b[j]
    //      => group with a, k in [0, n - 1]: a[k] <- \sum? * a[k]
    //      => greedily adapt b[k] w.r.t a[k], k in [0, n - 1]


    // Consider new a: a[k] <- \sum? * a[k], k in [0, n - 1]
    // 'largest' refers to absolute value
    //  Greedy: largest a[k] > 0 => largest b[k] < 0
    //          largest a[k] < 0 => largest b[k] > 0
    //  Otherwise: a[k] * b[k] > 0 => take the smallest of both

    // Can be done by sorting on both a and b
    // Then, simply go through 0 -> n - 1 and take the sum

    ll ans = 0;
    trick(a);
    // for (auto& v: a) cout << v << ' ';
    // cout << '\n';

    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());

    for(int i = 0; i < n; ++i)
        ans += a[i] * b[i];

    // vector <int> cnt(n);
    // for (int i = 0; i < n; ++i)
    //     for (int j = i; j < n; ++j)
    //         for (int k = i; k <= j; ++k)
    //             cnt[k]++;
    // for (auto& v: cnt) cout << v << ' ';

    cout << ans;


    return 0;
}