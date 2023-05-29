// Problem - https://cses.fi/problemset/task/1646

#include<bits/stdc++.h>
using namespace std;
 
struct SegTree{
	vector<long long> st;
	int n;
	SegTree(int _n) {
		this->n = _n;
		st.resize(4*n, 0);
	}
	void build(int start, int end, int node, vector<int>& v) {
		if(start == end) {
			st[node] = v[start];
			return;
		}
		int mid = (start + end)/2;
		build(start, mid, node*2+1, v);
		build(mid+1, end, node*2+2, v);
		st[node] = st[node*2+1] + st[node*2+2];
	}
	void update(int start, int end, int node, int& index, int& value) {
		if(start == end) {
			st[node] = value;
			return;
		}
		int mid = (start + end)/2;
		if(index <= mid) update(start, mid, node*2+1, index, value);
		else update(mid+1, end, node*2+2, index, value);
		st[node] = st[node*2+1] + st[node*2+2];
	}
	long long query(int start, int end, int node, int& l, int& r) {
		// no overlapping
		if(start > r || end < l) return 0;
		// complete overlapping
		if(start >= l && end <= r) return st[node];
		// partial overlapping
		int mid = (start+end)/2;
		long long left = query(start, mid, node*2+1, l, r);
		long long right = query(mid+1, end, node*2+2, l, r);
		return left+right;
	}
	void build(vector<int>& v) {
		build(0, n-1, 0, v);
	}
	void update(int index, int value) {
		update(0, n-1, 0, index, value);
	}
	long long query(int l, int r) {
		return query(0, n-1, 0, l, r);
	}
};
 
int main() {
	int n, q;
	cin >> n >> q;
	SegTree tree(n);
	vector<int> array(n);
	for(int i=0; i<n; i++) {
		cin >> array[i];
	}
	tree.build(array);
	for(int i=0; i<q; i++) {
		int l, r;
		cin >> l >> r;
		cout << tree.query(l-1, r-1) << endl;
	}
}