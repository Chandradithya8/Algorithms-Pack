#include<bits/stdc++.h>
using namespace std;

struct SegmentTree{
	vector<int> st, lazy;
	int n;
	void init(int _n) {
		this->n = _n;
		st.resize(4*n, 0);
		lazy.resize(4*n, 0);
	}

	void buildHelper(int start, int end, int node, vector<int>& v) {
		if(start == end) {
			st[node] = v[start];
			return;
		}

		int mid = (start + end)/2;
		buildHelper(start, mid, node*2+1, v);
		buildHelper(mid+1, end, node*2+2, v);
		st[node] = st[node*2+1] + st[node*2+2];
	}

	void updateHelper(int start, int end, int node, int l, int r, int value) {
		// not overlapping
		if(start > r || end < l) return;

		// lazy propagation
		if(lazy[node] != 0) {
			st[node] += lazy[node] * (end - start + 1);
			if(start != end) {
				lazy[node*2+1] += lazy[node];
				lazy[node*2+2] += lazy[node];
			}
			lazy[node] = 0;
		}

		// complete overlap -> update the given value
		if(start >= l && end <= r) {
			st[node] += value * (end - start + 1);
			if(start != end) {
				lazy[node*2+1] += value;
				lazy[node*2+2] += value;
			}
			return;
		}

		// partial overlap
		int mid = (start + end) / 2;
		updateHelper(start, mid, node*2+1, l, r, value);
		updateHelper(mid+1, end, node*2+2, l, r, value);
		st[node] = st[node*2+1] + st[node*2+2];
		return;
	}

	int queryHelper(int start, int end, int node, int l, int r) {
		// no overlapping
		if(start > r || end < l) return 0;

		// lazy propagation
		if(lazy[node] != 0) {
			st[node] += lazy[node] * (end - start + 1);
			if(start != end) {
				lazy[node*2+1] += lazy[node];
				lazy[node*2+2] += lazy[node];
			}
			lazy[node] = 0;
		}

		// complete overlapping
		if(start >= l && end <= r) return st[node];

		// partial overlapping
		int mid = (start+end)/2;
		int left = queryHelper(start, mid, node*2+1, l, r);
		int right = queryHelper(mid+1, end, node*2+2, l, r);
		return left+right;
	}

	void build(vector<int>& v) {
		buildHelper(0, n-1, 0, v);
	}

	void update(int l, int r, int value) {
		updateHelper(0, n-1, 0, l, r, value);
	}

	int query(int l, int r) {
		return queryHelper(0, n-1, 0, l, r);
	}
};

int main() {
	SegmentTree tree;
	int n, q;
	cin >> n >> q;
	vector<int> array(n);
	for(int i=0; i<n; i++) {
		cin >> array[i];
	}
	tree.init(n);
	tree.build(array);
	
	for(int i=0; i<q; i++) {
		int qtype;
		cin >> qtype;
		if(qtype == 2) {
			int index;
			cin >> index;
			cout << tree.query(index-1, index-1) << endl;
		}
		else {
			int l, r, value;
			cin >> l >> r >> value;
			tree.update(l-1, r-1, value);
		}
	}
}


/*
input
8 3
3 2 4 5 1 1 5 3
2 4
1 2 5 1
2 4


output
5
6
*/