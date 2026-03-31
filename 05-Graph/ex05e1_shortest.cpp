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
    while (!q.empty()) {
        int r = q.front().first, c = q.front().second;
        if (r == R-1 && c == C-1) break;
        q.pop();
        //4 ways to walk (up, down, left, right)
        if (c+1 < C && distance[r][c+1] == 0){
            distance[r][c+1] = distance[r][c] + 1;
            q.push({r,c+1});
        }
        if (r+1 < R && distance[r+1][c] == 0){
            distance[r+1][c] = distance[r][c] + 1;
            q.push({r+1,c});
        } 
        if (r-1 >= 0 && distance[r-1][c] == 0){
            distance[r-1][c] = distance[r][c] + 1;
            q.push({r-1,c});
        }
        if (c-1 >= 0 && distance[r][c-1] == 0){
            distance[r][c-1] = distance[r][c] + 1;
            q.push({r,c-1});
        }
    }
    if (distance[R-1][C-1] != 0) return distance[R-1][C-1];
    else return -1;
}