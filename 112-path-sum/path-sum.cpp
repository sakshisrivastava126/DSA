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
    bool solve(TreeNode* root, int target, int sum){
        if(!root) return false;

        sum += root->val;
        if(sum == target && !root->left && !root->right) return true;

        if(solve(root->left, target, sum)) return true;
        if(solve(root->right, target, sum)) return true;

        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        int sum = 0;
        return solve(root, targetSum, sum);
    }
};