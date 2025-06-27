class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for(char ch : tasks){
            freq[ch - 'A']++;
        }

        priority_queue<int> pq;
        for(int f : freq){
            if(f>0) pq.push(f);
        }

        int time=0;

         while (!pq.empty()) {
            vector<int> temp;
            int cycle = n + 1;

               while (cycle > 0 && !pq.empty()) {
                int curr = pq.top(); pq.pop();
                curr--;
                if (curr > 0) {
                    temp.push_back(curr); 
                }
                time++;
                cycle--;
            }

            for (int t : temp) {
                pq.push(t);
            }

            if (!pq.empty()) {
                time += cycle; 
            }
        }
        return time;
    }
};
