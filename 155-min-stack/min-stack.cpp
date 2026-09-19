class MinStack {
public:
    stack<pair<int, int>> st;
    int currMin = INT_MAX;
    MinStack() {
        
    }
    
    void push(int value) {
        currMin = min(currMin, value);  
        st.push({value, currMin});
    }
    
    void pop() {
       if(!st.empty()) st.pop();
       if(!st.empty())
        currMin = st.top().second;
       else currMin = INT_MAX;
    }
    
    int top() {
        if(!st.empty()) return st.top().first;
        return -1;
    }
    
    int getMin() {
        return currMin;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */