#include <bits/stdc++.h>

using namespace std;


const int x = 1997;

int main() {
    int n,k;
    cin >> n >> k;

    vector<vector<int>> dp(n+1, vector<int>(k+1, 0));

    //base case 
    for (int i=1; i<k+1; i++) dp[i][i] = 1;
    for (int i=1; i<n+1; i++) dp[i][1] = 1;

    for (int j=2; j<k+1; j++) {
        for (int i=j+1; i<n+1; i++) {
            int tmp1 = dp[i-1][j-1] % x;
            int tmp2 = (j * dp[i-1][j]) % x;
            dp[i][j] = (tmp1 + tmp2) % x;
        }
    } 

    cout << dp[n][k] << "\n";

}