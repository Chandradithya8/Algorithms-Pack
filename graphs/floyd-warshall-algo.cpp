#include<bits/stdc++.h>
using namespace std;

// multi source shortest path algorithm
// helps detect negative weight cycles

// O(v * v * v)
void shortest_distance(vector<vector<int>>&matrix){
    int n = matrix.size();
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(matrix[i][j] == -1) matrix[i][j] = 1e9;
            if(i == j) matrix[i][j] = 0;
        }
    }
    
    for(int k=0; k<n; k++) { // via
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }

    //check for negative cycle
    for(int i=0; i<n; i++) {
    	if(matrix[i][i] < 0) {
    		cout << "Has negative cycle" << endl;
    	}
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(matrix[i][j] == 1e9) matrix[i][j] = -1;
        }
    }
}

int main() {
	
}
