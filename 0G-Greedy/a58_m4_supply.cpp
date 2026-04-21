#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    map<int ,pair<int,int>> days;

    for (int i=0; i<K; i++){
        int d, e, l;
        cin >> d >> e >> l;
        days[d] =  {e,l};
    }

    queue<int> stock;
    queue<int> inLine;

    for (auto d : days) {
        int day = d.first;
        pair<int, int> task = d.second;
        if (task.first == 0) { //event A
            if (inLine.empty()) {
                stock.push(task.second);
                cout << 0 << "\n";
            } else {
                cout << inLine.front() << "\n";
                inLine.pop();
            }
        } else { //event B
            if (stock.empty()) {
                inLine.push(task.second);
                cout << 0 << "\n";
            } else {
                cout << stock.front() << "\n";
                stock.pop();
            }
        }
    }
}