#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, l;
    cin >> n >> l;
    vector<int> pi(n);
    for (int i=0; i<n; i++) cin >> pi[i];
    sort(pi.begin(), pi.end());

    int start = -1;
    int finish = -1;

    int i=0;
    int count = 0;
    while (i<n){
        if (pi[i] <= finish) {i++; continue;}
        else {
            start = pi[i];
            finish = start + l - 1;
            i++;
            count++;
        }
    }
    cout << count << "\n";
}