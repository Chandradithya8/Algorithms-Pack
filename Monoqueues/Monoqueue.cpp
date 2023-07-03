struct MaxQueue {
    deque<int> dq;
    queue<int> q;
    void enqueue(int x) {
        while(dq.size() and dq.back() < x) dq.pop_back();
        dq.push_back(x);
        q.push(x);
    }
    void dequeue() {
        int front = q.front();
        q.pop();
        if(dq.front() == front) dq.pop_front();
    }
    int getMax() {
        return dq.front();
    }
};

struct MinQueue {
    deque<int> dq;
    queue<int> q;
    void enqueue(int x) {
        while(dq.size() and dq.back() > x) dq.pop_back();
        dq.push_back(x);
        q.push(x);
    }
    void dequeue() {
        int front = q.front();
        q.pop();
        if(dq.front() == front) dq.pop_front();
    }
    int getMin() {
        return dq.front();
    }
};
