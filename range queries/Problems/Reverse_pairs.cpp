// Problem - https://leetcode.com/problems/reverse-pairs/

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
			st[node] += value;
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

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        SegTree tree(1LL*2*n);
        
        vector<long long> all;
        for(auto it : nums) {
            all.push_back(it);
            all.push_back(1LL*it*2);
        }
        
        sort(all.begin(), all.end());
        unordered_map<long long, long long> mp;
        for(int i=0; i<all.size(); i++) mp[all[i]] = i;
        
        int cnt = 0;
        for(int i=nums.size()-1; i>=0; i--) {
            cnt += tree.query(0, mp[nums[i]]-1);
            tree.update(mp[1LL*2*nums[i]], 1);
        }
        return cnt;
    }
};
