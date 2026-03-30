#include <bits/stdc++.h>

using namespace std;

void dfs_stack(int u, vector<int> &visited, vector<vector<int>> &adj, int v, int count);

int main() {
    int v, e;
    cin >> v >> e;
    vector<vector<int>> adj(v+1, vector<int>(v+1,0));
    for (int i=0; i<e; i++){
        int a, b;
        cin >> a >> b;
        adj[a][b] = 1; adj[b][a] = 1;
    }
    vector<int> visited(v+1, -1);
    int count = 1;
    for (int i=1; i<v+1; i++){
        if (visited[i] == -1) {
            dfs_stack(i, visited, adj, v, count);
            count++;
        }
    }
    /*
    for (auto &v : visited) cout << v << " ";
    cout << "\n";
    */
    cout << count-1 << "\n";
}

void dfs_stack(int u, vector<int> &visited, vector<vector<int>> &adj, int v, int count){
    stack<int> s;
    s.push(u);
    visited[u] = count;
    while (!s.empty()){
        int curr = s.top();
        s.pop();
        for (int i=1; i<v+1; i++){
            if (adj[curr][i] == 1 && visited[i] == -1){
                visited[i] = count;
                s.push(i);
            }
        }
    }
}
