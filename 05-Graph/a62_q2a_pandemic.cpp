#include <bits/stdc++.h>

using namespace std;

void bfs(int R, int C, int T, queue<pair<pair<int,int>,int>> &q, vector<vector<int>> &town, int &count) ;

int main() {
    int R, C, T;
    cin >> R >> C >> T;
    vector<vector<int>> town(R, vector<int>(C));
    queue<pair<pair<int,int>,int>> q; // pos(r,c) , days left
    int count = 0;
    for (int r=0; r<R; r++){
        for (int c=0; c<C; c++){
            cin >> town[r][c]; // 0 = not infected, 1 = infected, 2 = mountain(immune)
            if (town[r][c] == 1) {q.push({{r,c}, 0}); count++;}
        }
    }

    bfs(R, C, T, q, town, count);
    cout << count << "\n";
}

void bfs(int R, int C, int T, queue<pair<pair<int,int>,int>> &q, vector<vector<int>> &town, int &count) {
    //up down left right
    vector<int> dr = {-1, 1, 0, 0};
    vector<int> dc = {0, 0, -1, 1};

    while (!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        if (t==T) break;
        q.pop();
        for (int i=0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (0 <= nc && nc < C && 0 <= nr && nr < R && town[nr][nc] == 0){ //not infected and not a mountain
                town[nr][nc] = 1;
                //cout << "r: " << nr << " c: " << nc << " infected! on day: " << t+1 << "\n"; 
                count++;
                q.push({{nr, nc}, t+1});
            }
        }
    }
}