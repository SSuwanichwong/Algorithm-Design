#include <bits/stdc++.h>

using namespace std;

int bfs(int u, int k, int n, vector<vector<int>> &adj);

int main() {
    int n, e, k;
    cin >> n >> e >> k;
    vector<vector<int>> adj(n+1);
    for (int i=0; i<e; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout << bfs(0, k, n, adj) << "\n";

}

int bfs(int u, int k, int n, vector<vector<int>> &adj) {
    int count = 0;
    vector<int> distance(n+1, -1);
    queue<int> q;
    q.push(u);
    distance[u] = 0;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        if (distance[curr] == k);
        for (auto &a : adj[curr]) {
            if (distance[a] == -1) { //haven't passed yet
                distance[a] = distance[curr] + 1;
                if (distance[a] == k) count++;
                q.push(a);
            }
        }
    }
    return count;
}