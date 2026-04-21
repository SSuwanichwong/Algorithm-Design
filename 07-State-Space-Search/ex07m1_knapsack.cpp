#include <bits/stdc++.h>

using namespace std;

double heuristic(int i, double w, int n, vector<double> &price, vector<double> &weight, vector<pair<double, int>> &ratio);
double knapsack(int i, double currW, double currP, double w, int n, vector<double> &price, vector<double> &weight, vector<pair<double, int>> &ratio);

int main() {
    double w, n;
    cin >> w >> n;  
    vector<double> price(n);
    for (int i=0; i<n; i++) cin >> price[i]; 
    vector<double> weight(n);
    vector<pair<double, int>> ratio(n);
    for (int i=0; i<n; i++) {cin >> weight[i]; ratio[i] = {price[i] / weight[i], i};}
    sort(ratio.rbegin(), ratio.rend());
    
    cout << fixed << setprecision(4) << knapsack(0, 0, 0, w, n, price, weight, ratio) << "\n";
}

double knapsack(int i, double currW, double currP, double w, int n, vector<double> &price, vector<double> &weight, vector<pair<double, int>> &ratio){
    if (i < n) {
        int j = ratio[i].second;
        double maxed = 0;
        if (currW+weight[j] <= w) maxed = max(maxed, knapsack(i+1, currW+weight[j], currP+price[j], w, n, price, weight, ratio));
        double upper1 = heuristic(i+1, w-currW, n, price, weight, ratio);
        if (currP + upper1 >= maxed) maxed = max(maxed, knapsack(i+1, currW, currP, w, n, price, weight, ratio));
        return maxed;
    } else return currP;
}

double heuristic(int i, double w, int n, vector<double> &price, vector<double> &weight, vector<pair<double, int>> &ratio){
    double total = 0;
    double wght = 0;
    double pce = 0;
    while (i<n && wght < w) {
        int j = ratio[i].second;
        if (weight[j] <= w - wght) {
            wght += weight[j];
            pce += price[j];
        } else {
            pce += ratio[i].first * (w - wght);
            wght = w;
        }
        i++;
    }
    return pce;
}