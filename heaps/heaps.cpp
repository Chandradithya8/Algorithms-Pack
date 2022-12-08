#include <bits/stdc++.h>
using namespace std;

class heap {
public:
  int arr[100];
  int size;
  heap() {
    arr[0] = -1;
    size = 0;
  }
  
  void insert(int val) {
    size++;
    arr[size] = val;
    int index = size;
    while(index > 1) {
      int parent = index/2;
      if(arr[parent] < arr[index]) {
        swap(arr[parent], arr[index]);
        index = parent;
      }
      else return;
    }
  }
  
  void deleteElement() {
    // swap the first element with the last element and then delete the last element
    arr[1] = arr[size];
    size--;
    int index = 1;
    while(index <= size) {
      int left = 2*index;
      int right = 2*index+1;
      int maxi;
      if(left <= size) {
        maxi = left;
        if(right <= size && arr[right] > arr[left]) {
          maxi = right;
        }
      }
      if(arr[index] < arr[maxi]) {
        swap(arr[index], arr[maxi]);
        index = maxi;
      }
      else return;
    }
  }
  
  void display() {
    for(int i=1; i<=10; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
  
  void getTop() {
    cout << arr[1] << endl;
  } 
};


int main(){
    heap hp;
    
    // heap sort
    vector<int> arr = {65, 34, 75, 24, 23, 57, 24, 24, 24, 24};
    for(auto it : arr) {
      hp.insert(it);
    }
    while(hp.size != 0) {
      hp.getTop();
      hp.deleteElement();
    }
}

