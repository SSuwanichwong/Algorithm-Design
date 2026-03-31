#include <bits/stdc++.h>

using namespace std;

int bfs(int R, int C, pair<int, int> start, vector<vector<int>> &distance);

int main() {
    int R, C;
    cin >> R >> C;
    vector<vector<int>> dist(R, vector<int>(C, 0));
    for (int r=0; r<R; r++){
        string x; cin >> x;
        for (int c=0; c<C; c++){
            char y = x[c];
            if (y == '#') dist[r][c] = -1; //obstacle 
        }
    }
    
    cout << bfs(R,C,{0,0},dist) << "\n";
}

int bfs(int R, int C, pair<int, int> start, vector<vector<int>> &distance){
    queue<pair<int,int>> q;
    q.push(start);
    //4 ways to walk (up, down, left, right)
    vector<int> dr = {-1, 1, 0, 0};
    vector<int> dc = {0, 0, -1, 1};
    while (!q.empty()) {
        int r = q.front().first, c = q.front().second;
        if (r == R-1 && c == C-1) break;
        q.pop();
        for (int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (0 <= nr && nr < R && 0 <= nc && nc < C && distance[nr][nc] == 0){
                distance[nr][nc] = distance[r][c] + 1;
                q.push({nr,nc});
            }
        }
    }
    if (distance[R-1][C-1] != 0) return distance[R-1][C-1];
    else return -1;
}