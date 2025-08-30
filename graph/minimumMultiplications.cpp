// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        if(start == end) return 0;
        //we'll be treating each new number we get after multiplication as a node
        queue<pair<int,int>> q; //steps, nums
        q.push({start,0});
        
        vector<int> dis(100000, INT_MAX);
        dis[start] = 0;
        int mod = 100000;
        
        while(!q.empty()){
            int node = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            for(auto it : arr){
                int num = (it * node) % mod;
                if(steps+1 < dis[num]){
                    dis[num] = steps+1;
                    //if we reached end return steps
                    if(num==end) return steps+1;
                    //if we have not reached end push into the q
                    q.push({num, steps+1});
                }
            }
        }
        return -1;
    }
};
