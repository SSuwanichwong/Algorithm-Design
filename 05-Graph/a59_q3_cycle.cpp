#include <bits/stdc++.h>

using namespace std;

int dfs_find_cycle(int n, vector<vector<int>> &adj);

int main() {
    int n;
    cin >> n;

    //adjacency list
    vector<vector<int>> adj(n);
    for (int i=0; i<n; i++){
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cout << dfs_find_cycle(n, adj) << "\n";

}

int dfs_find_cycle(int n, vector<vector<int>> &adj){
    //any nodes with degree 1 cannot be in the cycle
    vector<int> degree(n);
    queue<int> q;
    for (int i=0; i<n; i++){
        degree[i] = adj[i].size();
        if (adj[i].size() == 1) q.push(i);
    }
    while (!q.empty()) {
        int node = q.front();
        for (auto &a : adj[node]){
            if (degree[a] > 1) {
                int con_node = a;
                degree[con_node]--;
                if (degree[con_node] == 1) q.push(con_node);
            }
        }
        q.pop();
    }

    int count = 0;
    for (auto &d : degree) if (d > 1) count++;
    return count;
}    