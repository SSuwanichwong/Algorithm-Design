#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> fs(n+1); //first = finish, second = start

    for (int i=1; i<n+1; i++) cin >> fs[i].second;
    for (int i=1; i<n+1; i++) cin >> fs[i].first;

    sort(fs.begin(), fs.end());

    int count = 0;
    int i=1;
    int currentstart = 0;
    int currentend = 0;

    while (i<n+1){
        if (fs[i].second >= currentend) {
            //printf("currstart: %i currend: %i nextend: %i nextend: %i\n", currentstart, currentend, fs[i].second, fs[i].first);
            currentstart = fs[i].second;
            currentend = fs[i].first;
            count++;
        }
        i++;
    }
    cout << count << "\n";
}