// Problem - https://leetcode.com/problems/handling-sum-queries-after-update/

#include<bits/stdc++.h>
using namespace std;

struct SegTreeLazy {
	vector<long long> st, lazy;
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
		long long mid = (start + end) / 2;
		build(start, mid, node*2+1, v);
		build(mid+1, end, node*2+2, v);
		st[node] = st[node*2+1] + st[node*2+2];
	}
	void update(int start, int end, int node, int& l, int& r) {
		// lazy propagate
		if(lazy[node]%2 == 1) {
			st[node] = (end-start+1) - st[node];
			if(start != end) {
				lazy[node*2+1] += lazy[node];
				lazy[node*2+2] += lazy[node];
			}
			lazy[node] = 0;
		}
        if(start > r || end < l) return;
		if(start >= l && end <= r) {
			st[node] = (end-start+1) - st[node];
			if(start != end) {
				lazy[node*2+1] += 1;
				lazy[node*2+2] += 1;
			}
			return;
		}
		long long mid = (start + end) / 2;
		update(start, mid, node*2+1, l, r);
		update(mid+1, end, node*2+2, l, r);
		st[node] = st[node*2+1] + st[node*2+2];
	}
	long long query(int start, int end, int node, int& l, int& r) {
		if(lazy[node]%2 == 1) {
			st[node] = (end-start+1) - st[node];
			if(start != end) {
				lazy[node*2+1] += lazy[node];
				lazy[node*2+2] += lazy[node];
			}
			lazy[node] = 0;
		}
        if(start > r || end < l) return 0;
		if(start >= l && end <= r) return st[node];
		long long mid = (start + end) / 2;
		long long left = query(start, mid, node*2+1, l, r);
		long long right = query(mid+1, end, node*2+2, l, r);
		return left + right;
	}
	void build(vector<int>& v) {
		build(0, n-1, 0, v);
	}
	void update(int l, int r) {
		update(0, n-1, 0, l, r);
	}
	long long query(int l, int r) {
		return query(0, n-1, 0, l, r);
	}
};

class Solution {
public:
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int n = nums1.size();
        SegTreeLazy tree(n);
        tree.build(nums1);
        long long total = accumulate(nums2.begin(), nums2.end(), 1LL*0);
        vector<long long> ans;
        
        for(auto it : queries) {
            if(it[0] == 1) tree.update(it[1], it[2]);
            else if(it[0] == 2) total += tree.query(0, n-1)*1LL*it[1];
            else ans.push_back(total);
        }
        return ans;
    }
};