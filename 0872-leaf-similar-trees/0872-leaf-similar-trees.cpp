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
   void check(TreeNode* root, vector<int> &arr){
        if(!root) return;
        if(!root->left && !root->right) arr.push_back(root->val);
        check(root->left, arr);
        check(root->right, arr);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> l1,l2;
        check(root1,l1);
        check(root2,l2);
        if(l1.size()!=l2.size()) return false;
        for(int i=0;i<min(l1.size(),l2.size()); i++){
            if(l1[i]!=l2[i]) return false;
        }
        return true;
    }
};