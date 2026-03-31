#include <bits/stdc++.h>

using namespace std;

vector<int> bfs_distK(int n, int k, vector<vector<int>> &adj);
int bfs(int u, int n, int k, vector<vector<int>> &adj);

int main() {
    int n, e, k;
    cin >> n >> e >> k;
    vector<vector<int>> adj(n);
    for (int i=0; i<e; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> degree = bfs_distK(n, k, adj);
    cout << *max_element(degree.begin(), degree.end()) << "\n";
}

vector<int> bfs_distK(int n, int k, vector<vector<int>> &adj){
    vector<int> degree(n);
    //start at student 0
    for (int i=0; i<n; i++){
        degree[i] = bfs(i, n, k, adj);
    }
    return degree;
}

int bfs(int u, int n, int k, vector<vector<int>> &adj){
    int count = 1;
    vector<int> dist(n, -1);
    queue<int> q;
    q.push(u);
    dist[u] = 0;
    while (!q.empty()){
        int curr = q.front();
        if (dist[curr] == k) break;
        q.pop();
        for (auto &a : adj[curr]){
            if (dist[a] == -1){
                dist[a] = dist[curr] + 1;
                if (dist[a] <= k) count++;
                q.push(a);
            }
        }
    }
    return count;
}