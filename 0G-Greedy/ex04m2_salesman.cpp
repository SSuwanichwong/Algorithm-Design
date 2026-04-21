#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll dist_cal(int x, int y, vector<int> &t, vector<int> &pt, int m) ;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> seq(M);
    vector<int> t(M);
    vector<int> pt(M, 0); //prefix sum of t
    for (int i=0; i<M; i++) cin >> seq[i];
    for (int i=0; i<M; i++) {
        cin >> t[i];
        if (i != M-1){
            pt[i+1] = t[i] + pt[i];
        } 
    }
    for (int i=0; i<N; i++) {
        int a, b;
        cin >> a >> b;
        ll total = 0;
        for (int i=0; i<M; i++){
            int curr = seq[i];
            int next = seq[(i+1) % M];
            ll tot = dist_cal(curr, next, t, pt, M);
            tot = min((ll)tot, dist_cal(curr, a, t, pt, M) + dist_cal(b, next, t, pt, M));
            tot = min((ll)tot, dist_cal(curr, b, t, pt, M) + dist_cal(a, next, t, pt, M));
            total += tot;
        }
        cout << total<< "\n";
    }

}

ll dist_cal(int x, int y, vector<int> &t, vector<int> &pt, int m) {
    if (x > y) { //make it so that y is always greater or equal to x
        swap(x, y);
    }

    ll clkw = pt[y] - pt[x];

    ll ctclkw = pt[m-1] - clkw + t[m-1];

    return min(clkw, ctclkw);
}