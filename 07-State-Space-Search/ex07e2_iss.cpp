#include <bits/stdc++.h>

using namespace std;

void recur(int curr, int current_sum, int goal, int &count);

int main(){
    int n;
    cin >> n;
    int count = 0;
    recur(1, 0, n, count);
    cout << count << "\n";
}

void recur(int curr, int current_sum, int goal, int &count){
    if (current_sum == goal) {count++; return;}
    for (int i=curr; i<=goal-current_sum; i++) {
        recur(i, current_sum+i, goal, count);
    }
}