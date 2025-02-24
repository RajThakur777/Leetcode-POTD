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
// //Brute force:
// class Solution {
// public:
//     void preorder(vector<int> &ans , TreeNode* root){
//         if(root == nullptr) return;

//         ans.push_back(root->val);
//         preorder(ans , root->left);
//         preorder(ans , root->right);
//     }

//     int kthSmallest(TreeNode* root, int k) {
//         vector<int> ans;
//         preorder(ans , root);

//         sort(ans.begin() , ans.end());

//         return ans[k-1];
//     }
// };





//Better Appraoch:
class Solution {
public:
    void inorder(int &ans , TreeNode* root , int &res , int k){
        if(root == nullptr) return;

        inorder(ans , root->left , res , k);
        res++;
        if(res == k){
            ans = root->val;
            return;
        }
        inorder(ans , root->right , res , k);
    }

    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        int res = 0;
        inorder(ans , root , res , k);

        return ans;
    }
};