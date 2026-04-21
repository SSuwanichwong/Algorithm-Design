#include <bits/stdc++.h>

using namespace std;

int main() {
    int f, w, n;// f = space with food n = amount of spaces w = bulb power
    cin >> f >> w >> n;
    vector<int> withFood;
    for (int i=0; i<f; i++) {
        int x;
        cin >> x;
        withFood.push_back(x);
    }
    sort(withFood.begin(), withFood.end());

    int count=0;
    int start = -1;
    int finish = -1;

    int i=0;
    while (i<f){
        if (withFood[i] <= finish) {i++; continue;}
        else {
            start = withFood[i];
            finish = start + 2*w;
            count++;
            i++;
        }
    }

    cout << count << "\n";

}