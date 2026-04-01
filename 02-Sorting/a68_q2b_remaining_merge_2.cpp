#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll merge_sort(string &binary, ll l, ll r, ll &count);
void merge(string &binary, ll l, ll m, ll r, ll &count, ll zero1, ll zero2);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    ll n;
    cin >> n;
    
    string binary;
    cin >> binary;

    ll count = 0;
    ll zero = merge_sort(binary, 0, n-1, count);
    cout << count << "\n";
}

ll merge_sort(string &binary, ll l, ll r, ll &count){
    if (l>=r) return (binary[l] == '0') ? 1 : 0;

    else {
        int m = (l+r)/2;
        ll zero1 = merge_sort(binary, l, m, count);
        ll zero2 = merge_sort(binary, m+1, r, count);
        merge(binary,l,m,r, count, zero1, zero2);
        return zero1 + zero2;
    }
}

void merge(string &binary, ll l, ll m, ll r, ll &count, ll zero1, ll zero2) {
    ll i = l, j = m+1;
    ll left_remain = m-l+1 - zero1;
    if (left_remain == 0) count += r-m-1+1;
    else {
        ll right_remain = r-m-1+1-zero2;
        if (right_remain == 0) count += left_remain;
        else count += right_remain;
    }
}