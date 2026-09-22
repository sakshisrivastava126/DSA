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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 1});
        long long ans=0;

        while(!q.empty()){
            unsigned long long sz = q.size();
            long long first = q.front().second;
            long long last = 0;

            while(sz--){
                TreeNode* node = q.front().first;
                long long i = q.front().second - first;
                q.pop();

                last = i;

                if(node->left)
                q.push({node->left, 2*i});
                if(node->right)
                q.push({node->right, 2*i+1});
            }
            ans = max(last+1, ans);
        }
        return ans;
    }
};