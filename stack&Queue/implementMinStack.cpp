class MinStack {
private:
    stack<pair<int, int>> s1;    
public:
    MinStack() {
        
    }
    
    void push(int val) {
        int minVal;
        if(s1.empty()){
            minVal = val;
        }
        else{
            minVal = min(val, s1.top().second);
        }
        s1.push({val, min(val, minVal)});
    }
    
    void pop() {
        s1.pop();
    }
    
    int top() {
        return s1.top().first;
    }
    
    int getMin() {
        return s1.top().second;
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
