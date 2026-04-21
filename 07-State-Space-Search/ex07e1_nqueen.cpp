#include <bits/stdc++.h>

using namespace std;


void recur(int r, int n, vector<int> &row, vector<bool> &used_col, int &count);

int main() {
    int n;
    cin >> n;

    int r = 0;
    int count = 0;
    vector<int> row(n); 
    vector<bool> used_col(n,false);

    recur(0, n, row, used_col, count);
    cout << count << "\n";
}

void recur(int r, int n, vector<int> &row, vector<bool> &used_col, int &count){
    if (r != 0) {
        for (int i=0; i<r-1; i++){
            if (r-1-i == abs(row[r-1] - row[i])) return;// delta row equals to delta col means diagonal
        }
    }

    if (r == n) {count++; return;}

    for (int i=0; i<n; i++){
        if (!used_col[i]) {
            used_col[i] = true;
            row[r] = i;
            recur(r+1, n, row, used_col, count);
            used_col[i] = false;
        }
    }
}