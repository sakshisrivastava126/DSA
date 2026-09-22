/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> ans;
    void solve(TreeNode* root, int target, vector<int>& arr, int sum){
        if(!root) return;
        
        sum += root->val;
        arr.push_back(root->val);

        if(!root->left && !root->right){
            if(sum == target) ans.push_back(arr);
        }

        solve(root->left, target, arr, sum);
        solve(root->right, target, arr, sum);
        arr.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> arr; int sum =0;
        solve(root, targetSum, arr, sum);
        return ans;
    }
};