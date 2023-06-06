#include<bits/stdc++.h>
using namespace std;

// Longest Common Prefix Suffix table
vector<int> computeLPS(string& pattern) {
    int n = pattern.size();
    vector<int> lps(n, 0);
    int i=1, j=0;
    while(i < n) {
        if(pattern[j] == pattern[i]) {
            lps[i] = j+1;
            i++;
            j++;
        }
        else {
            if(j != 0) j = lps[j-1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

bool KMP(string& text, string& pattern) {
    vector<int> lps = computeLPS(pattern);
    int n = text.size(), m = pattern.size();
    int i=0, j = 0;
    while(i < n and j < m) {
        if(text[i] == pattern[j]) {
            i++;
            j++;
        }
        else {
            if(j != 0) j = lps[j-1];
            else i++;
        }
    }
    if(j == m) return true;
    return false;
}

int main() {
	string str = "abcabyabc";
    string pattern = "abcax";
	cout << KMP(str, pattern) << endl;
}
