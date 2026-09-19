#define ll long long 
class MinStack {
public:
    stack<ll> st;
    long long prev = LLONG_MAX;
    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty()){
            st.push(value);
            prev = value;
        }
        else{
            if(value > prev){
                st.push(value);
            }
            else{
                long long to_push = 2LL*value - prev;
                st.push(to_push);
                prev = value;
            }
        }
    }
    
    void pop() {
        if(!st.empty()){
            ll val = st.top();
            st.pop();
            if(val < prev)
                prev = 2*prev - val;
            if(st.empty())
                prev = INT_MAX;
        }
    }
    
    int top() {
        if(!st.empty()){
            if(prev > st.top()) return prev;
            else return st.top();
        }
        return -1;
    }
    
    int getMin() {
        return prev;
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