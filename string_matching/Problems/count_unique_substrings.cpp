#include<bits/stdc++.h>
using namespace std;

int count_unique_substring(string& str) {
	int n = str.size();
	const long long mod = 1e9+7;
	const long long prime = 3;

	vector<long long> pow(n+1);
	pow[0] = 1;
	for(int i=1; i<n+1; i++) {
		pow[i] = (pow[i-1]*prime)%mod;
	}

	// calculate the hash
	vector<long long> hs(n+1, 0);
	for(int i=1; i<=n; i++) {
		hs[i] = (hs[i-1] + (str[i-1]-'a'+1) * pow[i-1])%mod;
	}

	long long cnt = 0;
	for(int len=1; len<=n; len++) {
		set<long long> st;
		for(int i=0; i+len<=n; i++) {
			long long curr = (hs[i+len] - hs[i] + mod)%mod;
			curr = (curr * pow[n-1-i]) % mod;
			st.insert(curr);
		}
		cnt += st.size();
	}

	return cnt;
}

int main() {
	string str = "abca";
	cout << count_unique_substring(str) << endl;
}
