class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        if(score.empty()) return {};

        int n = score.size();
        priority_queue<pair<int, int>> pq; //score, index
        vector<string> ans(n);

        for(int i=0; i<n; i++){
            pq.push({score[i], i});
        }

        int rank = 1;
        while (!pq.empty()) {
            int indx = pq.top().second;
            pq.pop();

            if (rank == 1) ans[indx] = "Gold Medal";
            else if (rank == 2) ans[indx] = "Silver Medal";
            else if (rank == 3) ans[indx] = "Bronze Medal";
            else ans[indx] = to_string(rank);

            rank++;
        }

        return ans;
    }
};
