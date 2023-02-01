#include<bits/stdc++.h>
using namespace std;

vector<long long> tree;
long long getSum(int node, int node_low, int node_high, int low, int high) {
	if(low>=node_low && high <= node_high) return tree[node];
	if(node_low > high || node_high < low) return 0;

	int mid = (low + high)/2;
	
	return getSum(2*node, node_low, node_high, low, mid) + 
		   getSum(2*node+1, node_low, node_high, mid+1, high);
}

// update
void update(int u, int v, int n) {
	tree[n+u] = v;
	for(int i=(n+u)/2; i>=1; i/=2) {
		tree[i] = tree[i*2] + tree[i*2+1];
	}
}

int main() {
	int n, q;
	cin >> n >> q;
	vector<int> arr(n);
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}

	// initial setup
	while(__builtin_popcount(n) != 1) {
		n++;
	}
	tree.resize(2*n, 0);

	// build tree
	for(int i=0; i<n; i++) {
		tree[n+i] = arr[i];
	}
	for(int i=n-1; i>=1; i--) {
		tree[i] = tree[i*2] + tree[i*2+1];
	}

	// get the sum
	for(int i=0; i<q; i++) {
		int type;
		cin >> type;
		if(type == 1) {
			int u, v;
			cin >> u >> v;
			u--;
			update(u, v, n);
		}
		else {
			int low, high;
			cin >> low >> high;
			low--;
			high--;
			cout << getSum(1, low, high, 0, n-1) << endl;
		}
	}
}
