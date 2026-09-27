#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second

int shell[3] = {1, 2, 3};   // correct shell location
int assume[3] = {0, 0, 0};  // correct initial shell
int n, a, b, g;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> n;
    while (n--)
    {
        cin >> a >> b >> g;
        swap(shell[a - 1], shell[b - 1]);
        assume[0] += (shell[g - 1] == 1);
        assume[1] += (shell[g - 1] == 2);
        assume[2] += (shell[g - 1] == 3);
        // cout << "\n";
        // for (int i = 0; i < 3; ++i)
        //     cout << shell[i] << " ";
        // cout << "\n";
        // for (int i = 0; i < 3; ++i)
        //     cout << assume[i] << " ";
        // cout << "\n";
    }
    cout << max({assume[0], assume[1], assume[2]});

    return 0;
}