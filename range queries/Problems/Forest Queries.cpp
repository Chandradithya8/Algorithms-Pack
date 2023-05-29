// Problem - https://cses.fi/problemset/task/1652/

#include<bits/stdc++.h>
using namespace std;
 
int main() {
	int n, q;
	cin >> n >> q;
	char ch;
	vector<vector<long long>> grid(n, vector<long long>(n, 0));
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> ch;
			if(ch == '*') grid[i][j] = 1;
		}
	}
 
	for(int i=0; i<n; i++) {
		for(int j=1; j<n; j++) {
			grid[i][j] += grid[i][j-1];
		}
	}
	for(int i=1; i<n; i++) {
		for(int j=0; j<n; j++) {
			grid[i][j] += grid[i-1][j];
		}
	}
 
	for(int i=0; i<q; i++) {
		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		l1 -= 1;
		r1 -= 1;
		l2 -= 1;
		r2 -= 1;
		long long ans = grid[l2][r2];
		if(l1-1 >= 0) ans -= grid[l1-1][r2];
		long long top_left = ((l1-1 >= 0 and l2-1 >= 0)? grid[l1-1][r1-1] : 0);
		if(r1-1 >= 0) {
			ans -= (grid[l2][r1-1] - top_left);
		}
		cout << ans << endl;
	}
}