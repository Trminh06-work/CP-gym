// Link: https://usaco.org/index.php?page=viewproblem2&cpid=526

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second


void solve(string &s, string &t){
    stack <char> st;
    for (int i = 0; i < t.size() - 1; ++i)
        st.push(s[i]);

    for (int i = t.size() - 1; i < s.size(); ++i){
        st.push(s[i]);
        if (st.size() < t.size()) continue;
        string tmp = "";
        bool equal = true;
        for (int j = t.size() - 1; j >= 0; --j){
            // cout << j << " " << st.top() << " " << t[j] << "\n";
            if (st.top() != t[j]){
                // cout << "here\n";
                equal = false;
                break;
            }
            tmp += st.top();
            st.pop();
        }
        if (!equal)
            for (int j = tmp.size() - 1; j >= 0; --j)
                st.push(tmp[j]);
    }

    string ans = "";
    while (!st.empty()){
        ans += st.top();
        // cout << st.top().fi << " " << st.top().se << "\n";
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    for (char ch: ans)
        cout << ch;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("censor.in",  "r", stdin);
    freopen("censor.out", "w", stdout);

    string s, t;
    cin >> s >> t;
    solve(s, t);

    return 0;
}