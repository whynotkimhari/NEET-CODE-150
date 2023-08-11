class MyStack {
private:
    queue<int> q1, q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int last;
        while(true) {
            if(q1.size() <= 0) break;
            if(q1.size() > 1) q2.push(q1.front());
            else last = q1.front();
            q1.pop();
        }

        while(!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
        return last;
    }
    
    int top() {
        int last;
        while(true) {
            if(q1.size() <= 0) break;
            q2.push(q1.front());
            last = q1.front();
            q1.pop();
        }

        while(!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
        return last;
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
