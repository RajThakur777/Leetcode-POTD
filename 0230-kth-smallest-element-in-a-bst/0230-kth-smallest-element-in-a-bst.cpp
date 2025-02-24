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
    void preorder(vector<int> &ans , TreeNode* root){
        if(root == nullptr) return;

        ans.push_back(root->val);
        preorder(ans , root->left);
        preorder(ans , root->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        preorder(ans , root);

        sort(ans.begin() , ans.end());

        return ans[k-1];
    }
};