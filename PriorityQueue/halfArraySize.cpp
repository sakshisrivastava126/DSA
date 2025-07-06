class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> freq;
        int ans=0;

        //count the freq of each num
        for(int it : arr){
            freq[it]++;
        }

        //add freqencies to maxheap
        priority_queue<int> pq;
        for (auto& [num, f] : freq) {
            pq.push(f);
        }
        
        //remove freqencies from heap until size is equal to or greater than half
        int toRemove = 0;
        while(toRemove < n/2){
            toRemove += pq.top();
            pq.pop();
            ans++;
        }
        return ans;
    }
};
