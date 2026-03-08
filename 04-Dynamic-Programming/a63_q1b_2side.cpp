#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, w, k; //n = kilometers , w = prohibited range, k = maximum amount of billboards
    cin >> n >> w >> k;
    vector<int> l(n+1), r(n+1);
    for (int i=0; i<n+1; i++) cin >> l[i]; //efficiency of left billboards
    for (int i=0; i<n+1; i++) cin >> r[i]; //efficiency of right billboards

}