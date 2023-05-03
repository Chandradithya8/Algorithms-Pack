#include<bits/stdc++.h>
using namespace std;

struct SegTreeLazy {
	vector<int> st, lazy;
	int n;
	SegTreeLazy(int _n) {
		this->n = _n;
		st.resize(4*n, 0);
		lazy.resize(4*n, 0);
	}
	void build(int start, int end, int node, vector<int>& v) {
		if(start == end) {
			st[node] = v[start];
			return;
		}
		int mid = (start + end) / 2;
		build(start, mid, node*2+1, v);
		build(mid+1, end, node*2+2, v);
		st[node] = st[node*2+1] + st[node*2+2];
	}
	void update(int start, int end, int node, int& l, int& r, int& value) {
		// lazy propagate
		if(lazy[node] != 0) {
			st[node] += lazy[node] * (end-start+1);
			if(start != end) {
				lazy[node*2+1] += lazy[node];
				lazy[node*2+2] += lazy[node];
			}
			lazy[node] = 0;
		}
		if(start > r || end < l) return;
		if(start >= l && end <= r) {
			st[node] += value * (end-start+1);
			if(start != end) {
				lazy[node*2+1] += value;
				lazy[node*2+2] += value;
			}
			return;
		}
		int mid = (start + end) / 2;
		update(start, mid, node*2+1, l, r, value);
		update(mid+1, end, node*2+2, l, r, value);
		st[node] = st[node*2+1] + st[node*2+2];
	}
	int query(int start, int end, int node, int& l, int& r) {
		if(lazy[node] != 0) {
			st[node] += lazy[node] * (end-start+1);
			if(start != end) {
				lazy[node*2+1] += lazy[node];
				lazy[node*2+2] += lazy[node];
			}
			lazy[node] = 0;
		}
		if(start > r || end < l) return 0;
		if(start >= l && end <= r) return st[node];
		int mid = (start + end) / 2;
		int left = query(start, mid, node*2+1, l, r);
		int right = query(mid+1, end, node*2+2, l, r);
		return left + right;
	}
	void build(vector<int>& v) {
		build(0, n-1, 0, v);
	}
	void update(int l, int r, int value) {
		update(0, n-1, 0, l, r, value);
	}
	int query(int l, int r) {
		return query(0, n-1, 0, l, r);
	}
};

int main() {
	vector<int> nums = {3, 4, 7, 6, 5, 4};
	int n = nums.size();
	SegTreeLazy tree(n);
	tree.build(nums);

	cout << tree.query(2, 4) << endl;
	tree.update(2, 5, 10);
	cout << tree.query(2, 4) << endl;
}
