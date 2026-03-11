#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> denominators(n+1);

    for (int i=1; i<n+1; i++) cin >> denominators[i];

    vector<vector<int>> dp(2, vector<int>(m+1)); //rolling array

    //base case 
    for (int i=0; i<m+1; i++) dp[0][i] = -1; // -1 means not possible

    for (int i=1; i<n+1; i++){
        int curr = i % 2;
        int prev = (i-1) % 2;
        int x = denominators[i];
        dp[curr][0] = 0; // 0 coins to make 0 baht

        for (int j=1; j<m+1; j++){
            int tmp1, tmp2; //tmp1 is if we are going to add the curr, tmp2 is not add the curr
            if (j-x>=0) tmp1 = dp[curr][j-x];
            else tmp1 = -1;

            tmp2 = dp[prev][j];

            if (tmp1 == -1 && tmp2 == -1) dp[curr][j] = -1;
            else if (tmp1 == -1 && tmp2 != -1) dp[curr][j] = tmp2;
            else if (tmp1 != -1 && tmp2 == -1) dp[curr][j] = tmp1+1;
            else dp[curr][j] = min(tmp1+1, tmp2);

        }    
    }

    cout << dp[n % 2][m] << "\n";
}