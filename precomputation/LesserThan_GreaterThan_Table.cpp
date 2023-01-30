vector<vector<int>> lesserThan(n, vector<int>(n, 0)), greaterThan(n, vector<int>(n, 0));
// build the greater than table
for(int i=0; i<n; i++) {
    int greater = 0;
    for(int j=i+1; j<n; j++) {
        if(nums[j] > nums[i]) greater++;
        greaterThan[i][j] = greater;
    }
}

// build the lesser than table
for(int i=1; i<n; i++) {
    int smaller = 0;
    for(int j=i-1; j>=0; j--) {
        if(nums[j] < nums[i]) smaller++;
        lesserThan[j][i] = smaller;
    }
}
