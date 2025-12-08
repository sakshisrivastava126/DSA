class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        //we'll use stack to store positive elems at beginning
        stack<int> st;

        for(int i=0; i < asteroids.size(); i++){
            //positive element : push into the stack
            if(asteroids[i]>=0) st.push(asteroids[i]);
            //if elem is negative
            else{
                //stack me elem hai + positive elem hai + element chhota hai negative elem se
                //then pos elem ko destroy krdo : remove from stack
                while(!st.empty() && st.top() > 0 && abs(asteroids[i]) > st.top()) st.pop();
                //agar stack me elem h and equal hai then dono se remove kro
                if(!st.empty() && abs(asteroids[i]) == st.top()){
                    st.pop(); //stack se remove kra
                    continue; //array se negative elem skip kra
                } 
                //abhi tak jitne pos elems mile sare destroy ho chuke hai
                //so we'll insert negative elems in the stack now
                //only if ya toh stack empty ho ya koi neg elem hi ho usme pehle se
                if(st.empty() || st.top() < 0){
                    st.push(asteroids[i]);
                }
            }
        } 
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
