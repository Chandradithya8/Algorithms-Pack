#include<bits/stdc++.h>
using namespace std;

// cnt the divisors of a number
// O(sqrt(n))
int findDivisors(int n) {
	int cnt = 0;
	for(int i=1; i*i<=n; i++){
		if(n%i == 0) {
			cnt++;
			if(n/i != i) cnt++;
		}
	}
	return cnt;
}

// cnt the divisors of all number in a range from 1....n
// O(n * log(n))
vector<int> findAllNumberDivisor(int n) {
	vector<int> div(n+1, 0);
	for(int i=1; i<=n; i++) {
		for(int j=i; j<=n; j=j+i) {
			div[j]++;
		}
	}
	return div;
}


// O(log(n))
bool checkForPrime(int n) {
	if(n == 2) return true;
	if(n%2 == 0) return false;
	for(int i=3; i*i <= n; i=i+2) {
		if(n%i == 0) return false;
	}
	return true;
}

// gcd
// gcd(a, b) = gcd(a, b-a)
// gcd(a, b)= gcd(b%a, a)

// O(log(max(a, b)))
int gcd(int a, int b) {
	if(a == 0) return b;
	return gcd(b%a, a);
}

int main() {
	int n;
	cin >> n;
	cout << checkForPrime(n) << endl;
}
