class MinStack {
private:
    stack<int> st;
    stack<int> min;
public:
    MinStack() {

    }
    
    void push(int val) {
        this->st.push(val);
        
        if(this->min.size() == 0) {
            min.push(val);
        }
        else {
            if(val < min.top()) {
                min.push(val);
            }
            else min.push(min.top());
        }
        return;
    }
    
    void pop() {
        this->min.pop();
        this->st.pop();
        return;
    }
    
    int top() {
        return this->st.top();
    }
    
    int getMin() {
        return this->min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
