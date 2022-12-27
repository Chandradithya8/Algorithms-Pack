#include <bits/stdc++.h>
using namespace std;

vector<string> split(string s, string del = " ") {
	vector<string> ans;
    int start, end = -1*del.size();
    do {
        start = end + del.size();
        end = s.find(del, start);
        ans.push_back(s.substr(start, end - start));
    } while (end != -1);
    
    return ans;
}

int main() {
	string str = "he is doing pretty well";
	vector<string> ans = split(str, "pretty");
	for(auto it : ans) cout << it << endl;
}
