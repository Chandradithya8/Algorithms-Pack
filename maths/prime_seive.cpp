#include<bits/stdc++.h>
using namespace std;

// finding prime numbers in a range
// O(N * log(log(N))
vector<bool> seive;
void primeSeive(int size) {
    seive.resize(size+1, 1);
    seive[0] = seive[1] = 0;
    for(long long i=2; i<=size; i++) {
        if(seive[i]) {
            for(long long j=i*i; j<=size; j=(j+i)) {
                seive[j] = 0;
            }
        }
    }
}

// find the least prime factor of a number in range 1 ... n
vector<long long> leastPrime;
void least_primeSeive(int size) {
    leastPrime.resize(size+1, 0);
    leastPrime[1] = 1;
    for(long long i=2; i<=size; i++) {
        if(leastPrime[i] == 0) {
        	leastPrime[i] = i;
            for(long long j=i*i; j<=size; j=(j+i)) {
                if(leastPrime[j] == 0) leastPrime[j] = i;
            }
        }
    }
}

int main() {
	primeSeive(100);
	for(int i=0; i<=90; i++) {
		if(seive[i]) cout << i << " ";
	}
	
	least_primeSeive(100);
	for(int i=0; i<=90; i++) {
		cout << i << " " << leastPrime[i] << endl;
	}
}
