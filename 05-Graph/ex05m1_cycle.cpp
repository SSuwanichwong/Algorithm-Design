#include <bits/stdc++.h>

using namespace std;

bool circuit_detect(int n, vector<vector<int>> &adj);
bool dfs_stack(int u, int n, vector<vector<int>> &adj, vector<int> &visited);

int main() {
    int t;
    cin >> t; // t graphs to check
    vector<string> out(t);
    for (int i=0; i<t; i++){
        int n, e;
        cin >> n >> e;
        // making adjacency list
        vector<vector<int>> adj(n);
        for (int j=0; j<e; j++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b); adj[b].push_back(a);
        }

        bool ans = circuit_detect(n, adj);
        if (ans) out[i] = "YES";
        else out[i]  = "NO";
    }

    for (auto &o : out) cout << o << "\n";
}

bool circuit_detect(int n, vector<vector<int>> &adj){
    vector<int> visited(n, -1);
    for (int u=0; u<n; u++){
        if (visited[u] == -1) { //unvisited
            if (dfs_stack(u,n,adj,visited)) return true;
        }
    }
    return false;
}

bool dfs_stack(int u, int n, vector<vector<int>> &adj, vector<int> &visited){ 
    //will get run through every node that is in the same connected comp as u
    stack<pair<int,int>> s; //pair of node and parent
    s.push({u, -1});
    visited[u] = 1;
    while (!s.empty()){
        int curr = s.top().first;
        int parent = s.top().second;
        s.pop();
        for (auto &a : adj[curr]){
            if (visited[a] == -1) {
                visited[a] = 1;
                s.push({a,curr});
            }
            else if (a != parent) return true; //if it is not just waling back from a->b to b->a == there is a cycle
        }
    }
    return false;
}