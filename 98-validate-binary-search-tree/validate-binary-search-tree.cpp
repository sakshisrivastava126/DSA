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
    bool solve(TreeNode* root, long largest, long smallest) {
        if(!root) return true;

        if(root->left && (root->val <= root->left->val || root->left->val <= smallest)) return false;
        if(root->right && (root->val >= root->right->val || root->right->val >= largest)) return false;

        bool l = solve(root->left, root->val, smallest);
        bool r = solve(root->right, largest, root->val);

        return l && r;
    }
    bool isValidBST(TreeNode* root) {
        return solve(root, LONG_MAX, LONG_MIN);
    }
};