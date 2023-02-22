#include<bits/stdc++.h>
using namespace std;

const int mod = 1e5+7;
long long binpow(long long a, long long b) {
	long long res = 1;
	while(b > 0) {
		if(b&1) res = (res * a)%mod;
		a = (a * a)%mod;
		b >>= 1;
	}
	cout << res << endl;
}

int main() {
	long long a, b;
	cin >> a >> b;
	cout << binpow(a, b) << endl;
}
