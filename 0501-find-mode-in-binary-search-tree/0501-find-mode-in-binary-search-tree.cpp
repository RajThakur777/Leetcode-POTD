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
//Brute force:
class Solution {
public:

    void inorder(vector<int> &ans , TreeNode* root){
        if(root == nullptr) return;

        inorder(ans , root->left);
        ans.push_back(root->val);
        inorder(ans , root->right);
    }

    vector<int> findMode(TreeNode* root) {    
        vector<int> ans;

        inorder(ans , root);

        map<int , int> mpp;
        for(int i=0; i<ans.size(); i++){
            mpp[ans[i]]++;
        }

        int maxi = INT_MIN;
        for(auto it : mpp){
            if(it.second > maxi){
                maxi = it.second;
            }
        }

        vector<int> res;
        for(auto it : mpp){
            if(it.second == maxi){
                res.push_back(it.first);
            }
        }
        return res;
    }
};