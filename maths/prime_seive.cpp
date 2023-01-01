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

int main() {
	primeSeive(100);

	for(int i=0; i<=90; i++) {
		if(seive[i]) cout << i << " ";
	}
}
