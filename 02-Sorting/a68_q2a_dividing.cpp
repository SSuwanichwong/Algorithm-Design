#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> spica;
    int spica_sum = 0, rigil_sum = 0;
    for (int i=0; i<n; i++){
        int x;
        cin >> x;
        spica.push_back({x, i+1});
        spica_sum += x;
    } 

    sort(spica.rbegin(), spica.rend());

    while (!spica.empty() && spica_sum - rigil_sum > 2 * spica.back().first) {
        int x = spica.back().first;
        spica_sum -= x;
        rigil_sum += x;
        spica.pop_back();
    }
    
    cout << spica.size() << "\n";
    for (auto &s : spica) cout << s.second << " ";
    cout << endl;
}