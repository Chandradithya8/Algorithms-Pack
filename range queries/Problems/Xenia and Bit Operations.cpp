// https://codeforces.com/contest/339/problem/D

#include <bits/stdc++.h>
using namespace std;

struct SegTree{
	vector<int> st;
	int n;
	SegTree(int _n) {
		this->n = _n;
		st.resize(4*n, 0);
	}
	void build(int start, int end, int node, vector<int>& v, int level) {
		if(start == end) {
			st[node] = v[start];
			return;
		}
		int mid = (start + end)/2;
		build(start, mid, node*2+1, v, !level);
		build(mid+1, end, node*2+2, v, !level);
		if(level == 0) st[node] = (st[node*2+1] | st[node*2+2]);
		else st[node] = (st[node*2+1] ^ st[node*2+2]);
	}
	void update(int start, int end, int node, int& index, int& value, int level) {
		if(start == end) {
			st[node] = value;
			return;
		}
		int mid = (start + end)/2;
		if(index <= mid) update(start, mid, node*2+1, index, value, !level);
		else update(mid+1, end, node*2+2, index, value, !level);
		if(level == 0) st[node] = (st[node*2+1] | st[node*2+2]);
		else st[node] = (st[node*2+1] ^ st[node*2+2]);
	}
	int query(int start, int end, int node, int& l, int& r, int level) {
		// no overlapping
		if(start > r || end < l) return 0;
		// complete overlapping
		if(start >= l && end <= r) return st[node];
		// partial overlapping
		int mid = (start+end)/2;
		int left = query(start, mid, node*2+1, l, r, !level);
		int right = query(mid+1, end, node*2+2, l, r, !level);
		if(level == 0) return (left | right);
		else return (left ^ right);
	}
	void build(vector<int>& v, int size) {
	  if(size%2 == 0) build(0, n-1, 0, v, 1);
		else build(0, n-1, 0, v, 0);
	}
	void update(int index, int value, int size) {
		if(size%2 == 0) update(0, n-1, 0, index, value, 1);
		else update(0, n-1, 0, index, value, 0);
	}
	int query(int l, int r, int size) {
		if(size%2 == 0) return query(0, n-1, 0, l, r, 1);
		else return query(0, n-1, 0, l, r, 1);
	}
};

int main() {
    int n, m;
    cin >> n >> m;
    int ele = pow(2, n);
    vector<int> arr(ele);
    SegTree tree(ele);
    for(int i=0; i<ele; i++) cin >> arr[i];
    tree.build(arr, n);
    
    for(int i=0; i<m; i++) {
      int ind, val;
      cin >> ind >> val;
      ind--;
      tree.update(ind, val, n);
      cout << tree.query(0, ele-1, n) << endl;
    }
}