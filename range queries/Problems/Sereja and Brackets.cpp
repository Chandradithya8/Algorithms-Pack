// https://codeforces.com/contest/380/problem/C

#include <bits/stdc++.h>
using namespace std;

struct info {
  int open, close, full;
  info() {
    open = 0;
    close = 0;
    full = 0;
  }
};

struct SegTree {
	vector<info> st;
	int n;
	SegTree(int _n) {
		this->n = _n;
		st.resize(4*n, info());
	}
	info merge(info s1, info s2) {
	  info result;
	  result.full = s1.full + s2.full + min(s1.open, s2.close);
	  result.open = s1.open + s2.open - min(s1.open, s2.close);
	  result.close = s1.close + s2.close - min(s1.open, s2.close);
	  return result;
	}
	void build(int start, int end, int node, auto& s) {
		if(start == end) {
			st[node].open = (s[start] == '(');
			st[node].close = (s[start] == ')');
			return;
		}
		int mid = (start + end)/2;
		build(start, mid, node*2+1, s);
		build(mid+1, end, node*2+2, s);
		st[node] =  merge(st[node*2+1], st[node*2+2]);
	}
	info query(int start, int end, int node, int& l, int& r) {
		// no overlapping
		if(start > r || end < l) return info();
		// complete overlapping
		if(start >= l && end <= r) return st[node];
		// partial overlapping
		int mid = (start+end)/2;
		info left = query(start, mid, node*2+1, l, r);
		info right = query(mid+1, end, node*2+2, l, r);
		return merge(left, right);
	}
	void build(auto& v) {
		build(0, n-1, 0, v);
	}
	info query(int l, int r) {
		return query(0, n-1, 0, l, r);
	}
};

int main() {
    string str;
    cin >> str;
    int size = str.size();
    int n;
    cin >> n;
    SegTree tree(size);
    tree.build(str);
    for(int i=0; i<n; i++) {
      int l, r;
      cin >> l >> r;
      l--, r--;
      cout << (tree.query(l, r).full * 2) << endl;
    }
}