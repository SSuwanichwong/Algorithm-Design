#include <bits/stdc++.h>

using namespace std;

vector<int> topo_sort(int n, vector<vector<int>> &adj, vector<int> &in_deg);

int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    vector<int> in_deg(n);
    for (int i=0; i<n; i++){
        int m;
        cin >> m;
        in_deg[i] = m;
        for (int j=0; j<m; j++){
            int x;
            cin >> x;
            adj[x].push_back(i); //x->i
        }
    }
    vector<int> ans = topo_sort(n, adj, in_deg);
    for (auto &a : ans) cout << a << " ";
    cout << "\n";
}

vector<int> topo_sort(int n, vector<vector<int>> &adj, vector<int> &in_deg) {
    vector<int> ans;
    queue<int> q;
    for (int i=0; i<n; i++){
        if (in_deg[i] == 0) {q.push(i);}
    }

    while (!q.empty()){
        int curr = q.front();
        ans.push_back(curr); 
        q.pop();
        for (auto &a : adj[curr]) {
            if (in_deg[a] > 0){
                in_deg[a]--;
                if (in_deg[a] == 0) q.push(a);
            }
        }
    }
    return ans;
}