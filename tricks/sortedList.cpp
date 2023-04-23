struct sortedList {
    void insert(vector<int>& v, int element) {
        auto it = lower_bound(v.begin(), v.end(), element);
        v.insert(it, element);
    }
    
    void remove(vector<int>& v, int element) {
        auto it = lower_bound(v.begin(), v.end(), element);
        if(it != v.end()) v.erase(it);
    }
    bool contains(vector<int>& v, int element) {
        return binary_search(v.begin(), v.end(), element);
    }
};
