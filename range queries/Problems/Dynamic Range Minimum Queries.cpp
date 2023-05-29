// Problem - https://cses.fi/problemset/task/1649/

#include<bits/stdc++.h>
using namespace std;
 
struct SegTree{
	vector<int> st;
	int n;
	void init(int _n) {
		this->n = _n;
		st.resize(4*n, 0);
	}
 
	void buildHelper(int start, int end, int node, vector<int>& v) {
		if(start == end) {
			st[node] = v[start];
			return;
		}
 
		int mid = (start + end)/2;
		buildHelper(start, mid, node*2+1, v);
		buildHelper(mid+1, end, node*2+2, v);
		st[node] = min(st[node*2+1], st[node*2+2]);
	}
 
	void updateHelper(int start, int end, int node, int index, int value) {
		if(start == end) {
			st[node] = value;
			return;
		}
 
		int mid = (start + end)/2;
		if(index <= mid) {
			updateHelper(start, mid, node*2+1, index, value);
		}
		else {
			updateHelper(mid+1, end, node*2+2, index, value);
		}
		st[node] = min(st[node*2+1], st[node*2+2]);
	}
 
	int queryHelper(int start, int end, int node, int l, int r) {
		// no overlapping
		if(start > r || end < l) return INT_MAX;
 
		// complete overlapping
		if(start >= l && end <= r) return st[node];
 
		// partial overlapping
		int mid = (start+end)/2;
		int left = queryHelper(start, mid, node*2+1, l, r);
		int right = queryHelper(mid+1, end, node*2+2, l, r);
		return min(left, right);
	}
 
	void build(vector<int>& v) {
		buildHelper(0, n-1, 0, v);
	}
 
	void update(int index, int value) {
		updateHelper(0, n-1, 0, index, value);
	}
 
	int query(int l, int r) {
		return queryHelper(0, n-1, 0, l, r);
	}
};

int main() {
	int n, q;
	SegTree tree;
	cin >> n >> q;
	tree.init(n);
	vector<int> array(n);
	for(int i=0; i<n; i++) {
		cin >> array[i];
	}
	tree.build(array);
	for(int i=0; i<q; i++) {
		int qtype, l, r;
		cin >> qtype >> l >> r;
		if(qtype == 1) {
			tree.update(l-1, r);
		}
		else {
			cout << tree.query(l-1, r-1) << endl;
		}
	}
}