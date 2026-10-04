// Link: https://dmoj.ca/problem/ccc08s4

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second

vector <char> ops_names = {'+', '-', '*', '/'};
vector <char> ops;
int res = -1;

int calc(int& a, int &b, char& op){
    switch (op){
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b != 0 && a % b == 0)
                return a / b;
            else
                return -1;
        default: return -1;
    }
}

int solve(vector <int>& c, vector <char>& ops){
    // no need to impose ordering on operators
    // only two possible combinations:
        // (a.b).(c.d) and ((a.b).c).d
    // hence for a.((b.c).d) -> ((b.c).d).a // in the permutation of vector<int> c
    int ans = -1e5;

    // for (auto& op: ops) cout << op << " ";
    // cout << "\n";

    // for (auto& card: c) cout << card << " ";
    // cout << "\n";

    // (a.b).(c.d)
    int a = calc(c[0], c[1], ops[0]);
    int b = calc(c[2], c[3], ops[2]);
    if (a != -1 && b != -1){
        b = calc(a, b, ops[1]);
        if (b!= -1 && b <= 24)
            ans = b;
    }

    // ((a.b).c).d
    a = calc(c[0], c[1], ops[0]);
    b = calc(a, c[2], ops[1]);
    if (a != -1 && b != -1){
        a = calc(b, c[3], ops[2]);
        if (a != -1 && a <= 24)
            ans = max(ans, a);
    }

    // (a.(b.c)).d
    a = calc(c[1], c[2], ops[1]);
    b = calc(c[0], a, ops[0]);
    if (a != -1 && b != -1){
        a = calc(b, c[3], ops[2]);
        if (a != -1 && a <= 24)
            ans = max(ans, a);
    }

    // cout << ans << "\n";
    return ans;
}

void gen_ops(int num, vector <int>& c){
    if (num == 3){
        int cur_calc = solve(c, ops);
        if (cur_calc <= 24)
            res = max(res, cur_calc);
        return;
    }

    for (char op: ops_names){
        ops.push_back(op);
        gen_ops(num + 1, c);
        ops.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("backforth.in", "r", stdin);
    // freopen("backforth.out", "w", stdout);

    int t; cin >> t;
    while (t--){
        vector <int> c(4);
        res = -1;
        for(auto& v: c) cin >> v;

        // order and arithmetic operator name
        sort(c.begin(), c.end());
        do {
            gen_ops(0, c);
        } while (next_permutation(c.begin(), c.end()));
        cout << res << "\n";
    }


    return 0;
}