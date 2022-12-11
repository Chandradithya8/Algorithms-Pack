#include<bits/stdc++.h>
using namespace std;

// summation
struct fenwick {
	vector<int> fn;
	int n;
	void init(int _n) {
		this->n = _n+1; // 1 based
		fn.resize(n, 0);
	}

	void add(int index, int value) {
		index++; // 1 based
		while(index < n) {
			fn[index] += value;
			index += (index & (-index)); // add the last set bit
		}
	}

	int queryHelper(int index) {
		index++;
		int ans = 0;
		while(index) {
			ans += fn[index];
			index -= (index & (-index)); // subtract the last set bit
		}
		return ans;
	}

	int query(int l, int r) {
		return queryHelper(r) - queryHelper(l-1);
	}
};

int main() {
	fenwick tree;
	int n, q;
	cin >> n >> q;
	tree.init(n);
	vector<int> array(n);
	for(int i=0; i<n; i++) {
		cin >> array[i];
		tree.add(i, array[i]);
	}
	for(int i=0; i<q; i++) {
		int qtype;
		cin >> qtype;
		if(qtype == 1) {
			int index, value;
			cin >> index >> value;
			index--;
			tree.add(index, value - array[index]);
		}
		else {
			int l, r;
			cin >> l >> r;
			cout << tree.query(l-1, r-1) << endl;
		}
	}
}

/*

input
8 4
3 2 4 5 1 1 5 3
2 1 4
2 5 6
1 3 1
2 1 4

output
14
2
11

*/