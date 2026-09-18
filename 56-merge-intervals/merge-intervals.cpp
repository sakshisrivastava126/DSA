class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& iv) {
        vector<vector<int>> ans;
        if(iv.size()==1) return iv;
        sort(iv.begin(), iv.end());

        int l = iv[0][0];
        int r = iv[0][1];
        for(int i=1; i<iv.size(); i++){
            int cl = iv[i][0];
            int cr = iv[i][1];
            if(r >= cl && r< cr){
                r = cr;
            }
            else if(r < cl){
                ans.push_back({l,r});
                l = cl, r=cr;
                continue;
            }
            else if(r>cl && r > cr){
                continue;
            }
        }
        ans.push_back({l, r});
        return ans;
    }
};