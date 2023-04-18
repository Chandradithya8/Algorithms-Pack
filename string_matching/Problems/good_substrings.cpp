// Problem Link - https://codeforces.com/problemset/problem/271/D

#include<bits/stdc++.h>
using namespace std;

int count_good_substring(string& str, string& alpha, int& k) {
	int n = str.size();
	const long long mod = 1e9+7;
	const long long prime = 37;

	vector<long long> pow(n+1);
	pow[0] = 1;
	for(int i=1; i<n+1; i++) {
		pow[i] = (pow[i-1]*prime)%mod;
	}

	// calculate the hash
	vector<pair<long long, long long>> hs(n+1, {0, 0});
	for(int i=1; i<=n; i++) {
		hs[i].first = (hs[i-1].first + (str[i-1]-'a'+1) * pow[i-1])%mod;
		hs[i].second = hs[i-1].second + (alpha[str[i-1]-'a'] == '0');
	}

	long long cnt = 0;
	for(int len=1; len<=n; len++) {
		set<long long> st;
		// long long cnt = 0;
		for(int i=0; i+len<=n; i++) {
			if(hs[i+len].second - hs[i].second > k) continue;
			long long curr = (hs[i+len].first - hs[i].first + mod)%mod;
			curr = (curr * pow[n-1-i]) % mod;
			st.insert(curr);
		}
		cnt += st.size();
	}

	return cnt;
}

int main() {
	string str, alpha;
	int k;
	cin >> str >> alpha >> k;
	cout << count_good_substring(str, alpha, k) << endl;
}
