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
    TreeNode* createBinaryTree(vector<vector<int>>& desc) {
        unordered_set<int> child;
        unordered_map<int, TreeNode*> mp;

        for(auto it : desc){
            int p = it[0];
            int c = it[1];
            int left = it[2];

            if(mp.find(p) == mp.end()){
                mp[p] = new TreeNode(p);
            }

            if(mp.find(c) == mp.end()){
                mp[c] = new TreeNode(c);
            }

            if(left){
                mp[p]->left = mp[c];
            }
            else{
                mp[p]->right = mp[c];
            }

            child.insert(c);
        }

        for(auto it : desc){
            if(child.find(it[0]) == child.end()){
                return mp[it[0]];
            }
        }
        return nullptr;
    }
};