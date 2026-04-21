#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> students(n, 0);
    vector<int> tasks(m);
    for (int i=0; i<m; i++) cin >> tasks[i];
    sort(tasks.begin(), tasks.end());

    int i = 0; 
    double total = 0;

    for (int j=0; j<m; j++){
        i %= n;
        students[i] += tasks[j];
        total += students[i];
        i++;
    }

    cout << fixed << setprecision(3) << total / m << "\n";
}