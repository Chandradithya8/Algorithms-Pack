// Problem - https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

#include<bits/stdc++.h>
using namespace std;

struct SegTree{
	vector<int> st;
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
	int query(int start, int end, int node, int& l, int& r) {
		// no overlapping
		if(start > r || end < l) return 0;
		// complete overlapping
		if(start >= l && end <= r) return st[node];
		// partial overlapping
		int mid = (start+end)/2;
		int left = query(start, mid, node*2+1, l, r);
		int right = query(mid+1, end, node*2+2, l, r);
		return left+right;
	}
	void build(vector<int>& v) {
		build(0, n-1, 0, v);
	}
	void update(int index, int value) {
		update(0, n-1, 0, index, value);
	}
	int query(int l, int r) {
		return query(0, n-1, 0, l, r);
	}
};

class Solution{
  	public:
    long long int inversionCount(long long nums[], long long n) {
      SegTree tree(n);
      vector<pair<long long, long long>> arr;
      
      for(int i=0; i<n; i++) arr.push_back({nums[i], i});
      sort(arr.begin(), arr.end());
      long long int count = 0;
      for(auto it : arr) {
        long long element = it.first;
        long long index = it.second;
        count += tree.query(index+1, n-1);
        tree.update(index, 1);
      }
      return count;
    }
};