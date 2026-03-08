#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, w, k; //n = kilometers , w = prohibited range, k = maximum amount of billboards
    cin >> n >> w >> k;
    vector<ll> l(n+1), r(n+1);
    for (int i=1; i<n+1; i++) cin >> l[i]; //efficiency of left billboards
    for (int i=1; i<n+1; i++) cin >> r[i]; //efficiency of right billboard

    if (k==n) {
        vector<long long> dpL(n+1), dpR(n+1);
        dpL[0] = 0; dpR[0] = 0;
        dpL[1] = l[1]; dpR[1] = r[1];
        if (n==1) {cout << max(l[1], r[1]) << "\n"; return 0;}
        
        for (int i=2; i<w+1; i++){
            dpL[i] = max(l[i], dpL[i-1]);
            dpR[i] = max(r[i], dpR[i-1]);
        }

        for (int i=w+1; i<n+1; i++){
            dpL[i] = max(dpL[i-1], l[i] + dpR[i-w-1]);
            dpR[i] = max(dpR[i-1], r[i] + dpL[i-w-1]);
        }

        cout << max(dpR[n], dpL[n]) << "\n";
    } else {
        vector<vector<ll>> dpL(n+1, vector<ll>(k+1)), dpR(n+1, vector<ll>(k+1));
        
        dpL[0][0] = 0; dpR[0][0] = 0;
        for (int i=0; i<n+1; i++){
            dpL[i][0] = 0;
            dpR[i][0] = 0;
            if (i<k+1) {dpL[0][i] = 0; dpR[0][i] = 0;}
        }

        for (int j = 1; j<k+1; j++){
            for (int i = 1; i<n+1; i++){
                if (i<w+1) {
                    dpL[i][j] = max(dpL[i-1][j], l[i]);
                    dpR[i][j] = max(dpR[i-1][j], r[i]);
                } else {
                    dpL[i][j] = max(dpL[i-1][j], l[i] + dpR[i-w-1][j-1]);
                    dpR[i][j] = max(dpR[i-1][j], r[i] + dpL[i-w-1][j-1]);
                }
            }
        }

        cout << max(dpL[n][k], dpR[n][k]) << "\n";
    }
    
}