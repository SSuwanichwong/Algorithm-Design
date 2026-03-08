#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; //number of billboard
    cin >> n;
    vector<int> billboards(n+1);
    for (int i=1; i<n+1; i++) cin >> billboards[i];

    if (n==1) {cout << billboards[1] << "\n"; return 0;}

    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = billboards[1];
    dp[2] = max(billboards[1], billboards[2]);

    for (int i=3; i<n+1; i++){
        int tmp1, tmp2;
        tmp1 = dp[i-1];
        tmp2 = dp[i-3] + billboards[i];
        dp[i] = max(tmp1, tmp2);
        
        //cout << "i: " << i << " value: " << dp[i] << "\n";
    }

    cout << dp[n] << "\n";
}