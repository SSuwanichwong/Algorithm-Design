#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, w, k; //n = kilometers , w = prohibited range, k = maximum amount of billboards
    cin >> n >> w >> k;
    vector<int> l(n+1), r(n+1);
    for (int i=1; i<n+1; i++) cin >> l[i]; //efficiency of left billboards
    for (int i=1; i<n+1; i++) cin >> r[i]; //efficiency of right billboards

    vector<long long> dpL(n+1), dpR(n+1);
    dpL[0] = 0; dpR[0] = 0;
    dpL[1] = l[1]; dpR[1] = r[1];
    if (n==1) {cout << max(l[1], r[1]) << "\n"; return 0;}
    
    for (int i=2; i<w+1; i++){
        dpL[i] = max((long long) l[i], dpL[i-1]);
        dpR[i] = max((long long) r[i], dpR[i-1]);
    }

    for (int i=w+1; i<n+1; i++){
        dpL[i] = max(dpL[i-1], l[i] + dpR[i-w-1]);
        dpR[i] = max(dpR[i-1], r[i] + dpL[i-w-1]);
    }

    cout << max(dpR[n], dpL[n]) << "\n";
}
