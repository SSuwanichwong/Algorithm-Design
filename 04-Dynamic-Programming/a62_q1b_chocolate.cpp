#include <bits/stdc++.h>

using namespace std;

const int x = 1000003;

int main() {
    int n, k; // n pieces size of set S
    cin >> n >> k;

    vector<int> s(k);
    for (int i=0; i<k; i++) cin >> s[i];

    vector<int> dp(n+1, 0); // dp[i] is the amount of method we can split for i pieces
    
    //base case
    dp[0] = 1; //0 pieces one method is don't eat

    for (int i=1; i<n+1; i++){
        for (auto &y : s) {
            if (i-y<0) continue;

            dp[i] += dp[i-y] % x; // eat y pieces check at i-y
        }
        dp[i] %= x;
    }

    cout << dp[n] << "\n";




}