#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n+1), w(n+1);

    for (int i=1; i<n+1; i++) cin >> v[i];
    for (int i=1; i<n+1; i++) cin >> w[i];

    vector<vector<int>> dp(n+1, vector<int>(m+1)); 

    for (int i=0; i<n+1; i++){
        for (int j=0; j<m+1; j++){
            cin >> dp[i][j];
        }
    }

    int i = n, j = m; //the answer for knapsack
    vector<int> picked;

    while (i != 0 && j != 0) {
        if (dp[i][j] == dp[i-1][j]) i--; //doesnt pick 
        else { //picked
            picked.push_back(i);
            j -= w[i];
            i--;
        } 

    }
    cout << picked.size() << "\n";

    for (auto &x : picked) cout << x << " ";
    cout << "\n";

}