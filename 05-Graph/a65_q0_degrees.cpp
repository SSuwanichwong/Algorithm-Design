#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);

    int n;
    cin >> n;
    vector<int> adj(n, 0);

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++) {
            int x;
            cin >> x;
            if (x == 1) adj[j] += 1;
        }
    }

    int k = *max_element(adj.begin(), adj.end());
    vector<int> out(k+1);

    for (auto &x : adj) out[x] += 1;

    for (auto &x : out) cout << x << " ";
    cout << "\n";
}