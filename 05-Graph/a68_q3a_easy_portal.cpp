#include <bits/stdc++.h>

using namespace std;

void bfs(int R, int C, vector<vector<int>> &dist, pair<int, int> start, pair<int, int> blackhole, pair<int, int> whitehole, pair<int, int> dest) ;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> dist(n, vector<int>(m, 0));
    // 0 = unvisited, >0 = visited with distance, -1 = wall
    pair<int, int> start, blackhole = {-1, -1}, whitehole = {-1, -1}, dest;

    for (int r=0; r<n; r++){
        string x;
        cin >> x;
        for (int c=0; c<m; c++) {
            if (x[c] == '#') dist[r][c] = -1;
            else if (x[c] == 'S') start = {r,c};
            else if (x[c] == 'B') blackhole = {r, c};
            else if (x[c] == 'W') whitehole = {r, c};
            else if (x[c] == 'T') dest = {r,c};
        }
    }
    
    bfs(n, m, dist, start, blackhole, whitehole, dest);

    if (dist[dest.first][dest.second] == 0) cout << "-1";
    else cout << dist[dest.first][dest.second] << "\n";

}

void bfs(int R, int C, vector<vector<int>> &dist, pair<int, int> start, pair<int, int> blackhole, pair<int, int> whitehole, pair<int, int> dest) {
    queue<pair<int, int>> q;
    q.push(start);
    dist[start.first][start.second] = 0;

    //up down left right
    vector<int> dr = {-1, 1, 0, 0};
    vector<int> dc = {0, 0, -1, 1};

    while (!q.empty()){
        if (dist[dest.first][dest.second] != 0) return;
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for (int i=0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (0 <= nr && nr < R && 0 <= nc && nc < C){ // in bound?
                if (dist[nr][nc] == 0) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
                if (blackhole.first == nr && blackhole.second == nc && dist[whitehole.first][whitehole.second] == 0){
                    dist[whitehole.first][whitehole.second] = dist[nr][nc] + 1;
                    q.push({whitehole.first, whitehole.second});
                } 
            }   
        }
    }
}