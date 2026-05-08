class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        
        queue<pair<int, int>> q;
        q.push({0, 0}); //idx, step

        //pre calculate all the prime numbers till the max element using sieve
        int maxi = *max_element(nums.begin(), nums.end());
        vector<bool> prime(maxi+1, true);
        prime[0] = prime[1] = false;
        for(int i=2; i*i<=maxi; i++){
            for(int j=i*2; j<=maxi; j+=i){
                prime[j] = false;
            }
        }

        //store all the indexes where you find an element
        vector<vector<int>> pos(maxi+1);
        for(int i=0; i<n; i++){
            pos[nums[i]].push_back(i);
        }
        vector<int> vis(n);
        vis[0]=1;
        //do bfs to find shortest path till the last ind
        
        while(!q.empty()){
            int idx = q.front().first;
            int step = q.front().second;
            q.pop();
            if(idx == n-1) return step;

            //push i-1 and i+1 indx and steps
            if(idx>0 && !vis[idx-1]){
                q.push({idx-1, step+1});
                vis[idx-1] = 1;
            }
            if(idx<n-1 && !vis[idx+1]){
                q.push({idx+1, step+1});
                vis[idx+1] = 1;
            }
            if(prime[nums[idx]]){ //if prime
                int p = nums[idx];
                for(int m=p; m<=maxi; m+=p){ //find all multiples of that prime number 
                //check whether it exist or not in the nums & if exist, push in the q
                    for(auto it : pos[m]){ 
                        if(!vis[it]){
                            q.push({it, step+1});
                            vis[it] = 1;
                        }
                    }
                    pos[m].clear(); //clear that number completely so we dont keep revisiting again and again
                }
                prime[p]=false; //mark prime as false coz we have already visited
            }
        }
        return n-1;
    }
};