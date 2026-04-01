#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxT = pow(10, 9);

vector<ll> dijkstra(int n, vector<vector<pair<int, ll>>> &adj, int u);

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, ll>>> adj(n+1); //pair pos1 -> pos2, time
    for (int i=0; i<m; i++){
        int a,b;
        ll t;
        cin >> a >> b >> t;
        adj[a].push_back({b,t});
        adj[b].push_back({a,t});
    }

    vector<ll> dijk = dijkstra(n,adj,1);

    ll maxed = *max_element(dijk.begin(), dijk.end());
    for (int i=2; i<n+1; i++){
        cout << maxed - dijk[i] << "\n";
    }
}

vector<ll> dijkstra(int n, vector<vector<pair<int, ll>>> &adj, int u){
    vector<ll> dist(n+1);
    vector<int> prev(n+1);
    for (int i=1; i<n+1; i++){dist[i] = maxT; prev[i] = -1;}
    set<pair<ll,int>> s; // time, node
    s.insert({0, u});
    dist[u] = 0;
    while (!s.empty()){
        ll t = s.begin()->first;
        int curr = s.begin()->second;
        s.erase({t, curr});
        for (auto &a : adj[curr]){
            if (dist[a.first] > t + a.second){
                if (s.find({dist[a.first], a.first}) != s.end()) {
                    s.erase({dist[a.first], a.first});
                }
                dist[a.first] = t + a.second; 
                prev[a.first] = curr;
                s.insert({dist[a.first], a.first});
            }
        }
    }
    return dist;
}