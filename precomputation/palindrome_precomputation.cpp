vector<vector<int>> dp(n, vector<int>(n, 0));
for(int i=0; i<n; i++) {
    dp[i][i] = 1;
}

for(int len=2; len<=n; len++) {
    for(int i=0; i+len-1<n; i++) {
        int j = i+len-1;
        if(i+1 == j) dp[i][j] = (s[i] == s[j]);
        else dp[i][j] = (s[i] == s[j] && dp[i+1][j-1]);
    }
}
