#include <bits/stdc++.h>

using namespace std;  

typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<ll> goats(n);
    for (int i=0; i<n; i++) cin >> goats[i];
    sort(goats.begin(), goats.end());

    int i=0;
    int j=1;
    ll dmg = 0;

    while (i<n && j<n && i != j){
        ll curr = goats[i] * goats[j];
        dmg += curr;
        i = j;
        j++;
    }

    cout << dmg << "\n";

}