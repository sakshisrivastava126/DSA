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
    bool solve(TreeNode* root, int tar, string& s){
        if(root == NULL) return false;

        if(root->val == tar) return true;

        s.push_back('L');
        if(solve(root->left, tar, s)) return true;
        s.pop_back();

        s.push_back('R');
        if(solve(root->right, tar, s)) return true;
        s.pop_back();

        return false;
    }
    string getDirections(TreeNode* root, int sv, int dv) {
        string s1="";
        string s2="";
        solve(root, sv, s1);
        solve(root, dv, s2);

        int l=0;
        while(l < s1.size() && l< s2.size()){
            if(s1[l] != s2[l]) break;
            l++;
        }
        string ans = "";
        for(int i=l; i<s1.size(); i++){
            ans += 'U';
        }
        for(int i=l; i<s2.size(); i++){
            ans += s2[i];
        }
        return ans;
    }
};