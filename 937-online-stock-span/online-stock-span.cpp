class StockSpanner {
public:
    stack<pair<int, int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int ans=1;
        if(st.empty() || st.top().first > price){
            st.push({price, 1});
            return 1;
        }
        else{
            while(!st.empty() && st.top().first <= price){
                ans += st.top().second;
                st.pop();
            }
            st.push({price, ans});
        }
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */