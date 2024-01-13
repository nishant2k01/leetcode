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
    int traverse(TreeNode* root, int start,int &mx){
        if(root==NULL) return mx;
        mx=max(mx,root->val);
        traverse(root->left,start,mx);
        traverse(root->right,start,mx);
        return mx;
    }
 
    void createAdj(vector<vector<int>>&adj,TreeNode * root){
        if(root==NULL) return;
 
        if(root->left!=NULL){
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
            createAdj(adj,root->left);
        }
        if(root->right!=NULL){
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
            createAdj(adj,root->right);
        }
        return;
    }
 
    int infectionTrack(int start,vector<bool> &isInfected, vector<vector<int>>&adj){

        queue<pair<int,int>>q;
        q.push({start,0});
        int time=0;
        isInfected[start]=true;

        while(!q.empty()){
            pair<int,int> top=q.front();
            int x=top.first;
            int freq=top.second;
            q.pop();
            if(adj[x].size()==0){
                continue;
            }
            isInfected[x]=true;
 
            for(int i=0;i<adj[x].size();i++){
                if(!isInfected[adj[x][i]]){
                    q.push({adj[x][i],freq+1});
                }
            }
            time=max(time,freq); 
        }
        return time;
    }
 
    int amountOfTime(TreeNode* root, int start) {
        if(root==NULL) return 0;
        int mx=0;
        mx=traverse(root,start,mx);
        vector<vector<int>>adj(mx+1);
        vector<bool> isInfected(mx+1);
        createAdj(adj,root);
        return infectionTrack(start,isInfected,adj);
    }
};