#include<bits/stdc++.h>
using namespace std;

void rabinKarp(string& s, string& p) {
	vector<int> index;
	const long long mod = 1e9+7;
	const long long prime = 31;

	long long n = s.size();
	long long m = p.size();

	// calculate the power
	vector<long long> pow(max(n, m)+1, 0);
	pow[0] = 1;
	for(int i=1; i<(int)pow.size(); i++) {
		pow[i] = (pow[i-1]*prime)%mod;
	}

	// hash for the text
	vector<long long> h_s(n, 0);
	for(int i=0; i<n; i++) {
		long long prev = (i-1 < 0 ? 0 : h_s[i-1]);
		h_s[i] = (prev + (s[i]-'a'+1)*pow[i])%mod;
	}

	// hash for the pattern
	long long h_p = 0;
	for(int i=0; i<m; i++) {
		h_p = (h_p + (p[i]-'a'+1)*pow[i])%mod;
	}

	// first index
	if(h_s[m-1] == h_p) index.push_back(0);

	for(int i=0; i+m<n; i++) {
		long long curr = (h_s[i+m] - h_s[i] + mod)%mod;
		long long tmp = (h_p * pow[i+1])%mod;
		if(curr == tmp) index.push_back(i+1);
	}

	// for(auto it : index) cout << it << " ";
	// cout << endl;

	cout << index.size() << endl;
}

int main() {
	string t, s;
	cin >> t >> s;
	rabinKarp(t, s);
}
