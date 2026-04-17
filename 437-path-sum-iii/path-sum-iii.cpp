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
    int tar;
    int cnt=0;
    unordered_map<long long, int> mp;

    void solve(TreeNode* root, long long currSum){
        if(!root) return ;

        currSum += root->val;

        cnt += mp[currSum-tar];

        mp[currSum]++;

        solve(root->left, currSum);
        solve(root->right, currSum);
        mp[currSum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        tar= targetSum;
        mp[0]=1;
        solve(root, 0);
        return cnt;
    }
};