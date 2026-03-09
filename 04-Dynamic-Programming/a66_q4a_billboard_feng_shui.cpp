#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> billboards(n+1);

    ll pattern = 0;
    for (int i=1; i<n+1; i++) cin >> billboards[i];
    for (int i=0; i<k; i++){
        int p; cin >> p;
        if (p) pattern |= 1LL << (k-1-i); // stores pattern as bits (bitmask)
    }

    const ll x = 1 << k;
    vector<vector<ll>> dp(2, vector<ll>(x, -1)); // (rolling array) storing data at i and i-1 (inside each is a pattern of the last i bit)

    // base case dp[0][*] = -1;

    dp[0][0] = 0; // base case

    for (int i=1; i < n+1; i++) {
        int prev = (i-1) % 2;
        int current = i%2;

        for (int j=0; j<x; j++) dp[current][j] = -1; //clearing

        for (int mask = 0; mask < x; mask++) {
            if (dp[prev][mask] == -1) continue;
            int next0 = (mask << 1) & ((1 << k) - 1); // next0 is the last k bits
            
            // i is less than k we doesnt check for pattern yet
            if (i<k || next0 != pattern){
                dp[current][next0] = max(dp[current][next0], dp[prev][mask]); // the maximum for current with the last k pattern as next0
            }

            if ((mask & 1) != 1){
                int next1 = ((mask << 1) + 1) & ((1 << k) - 1); 
                if (i<k || next1 != pattern){
                    dp[current][next1] = max(dp[current][next1], dp[prev][mask] + billboards[i]);
                }
            }
        }
    }

    ll ans = 0;
    int curr = n % 2;
    for (int i=0; i<x; i++){
        ans = max(ans, dp[curr][i]);
        //cout << "i: " << i << " value: " << dp[curr][i] << "\n";
    }
    cout << ans << "\n";
}