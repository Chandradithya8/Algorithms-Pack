// Problem - https://cses.fi/problemset/task/1648/

#include<bits/stdc++.h>
using namespace std;

struct SegTree{
	vector<long long> st;
	long long n;
	SegTree(long long _n) {
		this->n = _n;
		st.resize(4*n, 0);
	}
	void build(long long start, long long end, long long node, vector<long long>& v) {
		if(start == end) {
			st[node] = v[start];
			return;
		}
		long long mid = (start + end)/2;
		build(start, mid, node*2+1, v);
		build(mid+1, end, node*2+2, v);
		st[node] = st[node*2+1] + st[node*2+2];
	}
	void update(long long start, long long end, long long node, long long& index, long long& value) {
		if(start == end) {
			st[node] = value;
			return;
		}
		long long mid = (start + end)/2;
		if(index <= mid) update(start, mid, node*2+1, index, value);
		else update(mid+1, end, node*2+2, index, value);
		st[node] = st[node*2+1] + st[node*2+2];
	}
	long long query(long long start, long long end, long long node, long long& l, long long& r) {
		// no overlapping
		if(start > r || end < l) return 0;
		// complete overlapping
		if(start >= l && end <= r) return st[node];
		// partial overlapping
		long long mid = (start+end)/2;
		long long left = query(start, mid, node*2+1, l, r);
		long long right = query(mid+1, end, node*2+2, l, r);
		return left+right;
	}
	void build(vector<long long>& v) {
		build(0, n-1, 0, v);
	}
	void update(long long index, long long value) {
		update(0, n-1, 0, index, value);
	}
	long long query(long long l, long long r) {
		return query(0, n-1, 0, l, r);
	}
};

int main() {
	long long n, m;
	cin >> n >> m;
	vector<long long> array(n);
	for(long long i=0; i<n; i++) cin >> array[i];
	SegTree tree(n);
	tree.build(array);
	for(long long i=0; i<m; i++) {
		long long a, b, c;
		cin >> a >> b >> c;
		if(a == 2) {
			b--, c--;
			cout << tree.query(b, c) << endl;
		}
		else {
			b--;
			tree.update(b, c);
		}
	}
}
