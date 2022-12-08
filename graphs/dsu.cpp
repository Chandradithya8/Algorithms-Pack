#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
	vector<int> rank, parent, size;
	DisjointSet(int n) {
		rank.resize(n+1, 0);
		parent.resize(n+1, 0);
		size.resize(n+1, 1);
		for(int i=0; i<=n; i++) {
			parent[i] = i;
			size[i] = 1;
		}
	}

	int findParent(int node) {
		if(parent[node] == node) 
			return node;
		return parent[node] = findParent(parent[node]);
	}

	void unionByRank(int u, int v) {
		int u_par = findParent(u);
		int v_par = findParent(v);
		if(u_par == v_par) return;

		if(rank[u_par] < rank[v_par]) {
			parent[u_par] = v_par;
		}
		else if(rank[v_par] < rank[u_par]) {
			parent[v_par] = u_par;
		}
		else {
			parent[v_par] = u_par;
			rank[u_par]++;
		}
	}

	// use this
	void unionBySize(int u, int v) {
		int u_par = findParent(u);
		int v_par = findParent(v);
		if(u_par == v_par) return;
		if(size[u_par] < size[v_par]) {
			parent[u_par] = v_par;
			size[v_par] += size[u_par];
		}
		else {
			parent[v_par] = u_par;
			size[u_par] += size[v_par];
		}
	}
};

int main() {
	DisjointSet ds(7);
	ds.unionBySize(1, 2);
	ds.unionBySize(2, 3);
	ds.unionBySize(4, 5);
	ds.unionBySize(6, 7);
	ds.unionBySize(5, 6);
	
	if(ds.findParent(3) == ds.findParent(7)) {
		cout << "same" << endl;
	}
	else cout << "not same" << endl;

	ds.unionBySize(3, 7);
	
	if(ds.findParent(3) == ds.findParent(7)) {
		cout << "same" << endl;
	}
	else cout << "not same" << endl;
}
