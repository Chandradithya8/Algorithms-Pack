bool isPal[2000][2000] = {};
for(int i = s.size() - 1; i >= 0; --i) {
    for(int j = i; j < s.size(); ++j)
        isPal[i][j] = s[i] == s[j] ? i + 1 >= j || isPal[i + 1][j - 1] : false;
}
