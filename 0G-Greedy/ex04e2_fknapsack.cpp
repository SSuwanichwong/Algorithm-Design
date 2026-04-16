#include <bits/stdc++.h>

using namespace std;

int main() {
    double w;
    int n;
    cin >> w >> n;
    vector<double> price(n+1);
    vector<double> weight(n+1);

    for (int i=0; i<n; i++) cin >> price[i+1];
    for (int i=0; i<n; i++) cin >> weight[i+1];

    vector<pair<double, int>> value(n);
    for (int i=0; i<n; i++) value[i] = {price[i+1] / weight[i+1], i+1};

    sort(value.begin(), value.end());

    double remain = w;
    double total = 0;
    int i = n-1; //point at the highest value item 

    while (true) {
        if (remain == 0 or i < 0) break;
        
        pair<double, int> current = value[i];

        if (remain >= weight[current.second]) {
            total += price[current.second];
            remain -= weight[current.second];
            i--;
        }
        else {
            total += current.first * remain;
            remain = 0;
            i--;
        }

        //cout << "total: " << total << " i : " << i << "\n";
    }
    
    cout << total << "\n";
}