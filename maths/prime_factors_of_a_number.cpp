// Approach 1 - Faster
#include <bits/stdc++.h>
using namespace std;

bool prime(long long n) {
	if(n%2 == 0) return false;
	if(n == 2) return true;
	for(long long i=3; i<=sqrt(n); i=i+2) {
		if(n%i == 0) return false;
	}
	return true;
}

// log(n) * log(n)
vector<long long> primeFactors(long long n) {
	vector<long long> all;
	long long c = 2;
	while(n > 1) {
		if(prime(n)) {
			all.push_back(n);
			return all;
		}
		if(n%c == 0) {
			n /= c;
			all.push_back(c);
		}
		else c++;
	}
	return all;
}

int main() {
	vector<long long> all = primeFactors(365657575);
	for(auto it : all) cout << it << endl;
}



// Approach 2
#include<bits/stdc++.h>
using namespace std;

// finding prime factors of a number
// sqrt(n)
vector<int> PrimeFactors(int n) {
    vector<int> ans;
    while (n % 2 == 0) {
        ans.push_back(2);
        n = n/2;
    }
 
    for (int i = 3; i <= sqrt(n); i = i + 2) {
        while (n % i == 0) {
            ans.push_back(i);
            n = n/i;
        }
    }

    if (n > 2)
        ans.push_back(n);
    return ans;
}

int main() {
	int n = 10;
	vector<int> ans = PrimeFactors(n);
	while(ans.size() != 1) {
		int _sum = 0;
		for(auto it : ans) {
			_sum += it;
		}
		ans = PrimeFactors(_sum);
	}
	cout << ans[0] << endl;
}
