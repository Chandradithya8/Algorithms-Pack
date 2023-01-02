#include<bits/stdc++.h>
using namespace std;

vector<unsigned long long int> dp;
int findCatalan(int n) {
	dp.resize(n+1, 0);
	dp[0] = dp[1] = 1;
	for(int i=2; i<=n; i++) {
		for(int j=0; j<i; j++) {
			dp[i] += dp[j] * dp[i-1-j];
		}
	}
	return dp[n];
}

int main() {
	cout << findCatalan(19) << endl;
	for(auto it : dp) cout << it << " ";
}
