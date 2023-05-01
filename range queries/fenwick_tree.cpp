#include<bits/stdc++.h>
using namespace std;

struct BIT {
    vector<int> fn;
    int n;
    BIT(int n) {
        this->n = n;
        fn.resize(n+1, 0);
    }
    void add(int x, int y) {
        x++;
        while(x <= n) {
            fn[x] += y;
            x += (x & (-x));
        }
    }
    int sum(int x) {
        x++;
        long long ans = 0;
        while(x > 0) {
            ans += fn[x];
            x -= (x & (-x));
        }
        return ans;
    }
    int sum(int l, int r) {
        return sum(r) - sum(l-1);
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    BIT bit(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    for(int i=0; i<n; i++) bit.add(i, arr[i]);
    for(int i=0; i<m; i++) {
        int l, r;
        cin >> l >> r;
        cout << bit.sum(l-1, r-1) << endl;
    }
}


/*

input
8 4
3 2 4 5 1 1 5 3
2 1 4
2 5 6
1 3 1
2 1 4

output
14
2
11

*/
