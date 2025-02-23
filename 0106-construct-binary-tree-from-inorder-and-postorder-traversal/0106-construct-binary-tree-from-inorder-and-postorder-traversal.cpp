// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// //Recursion:
// class Solution {
// public:

//     TreeNode* helper(vector<int>& inorder , vector<int>& postorder , int start , int end , int &idx){
//         if(idx < 0 || start > end) return NULL;

//         int rootVal = postorder[idx];

//         int valueIdx = 0;
//         for(int i=start; i<=end; i++){
//             if(inorder[i] == rootVal){
//                 valueIdx = i;
//                 break;
//             }
//         }
//         idx--;

//         TreeNode* root = new TreeNode(rootVal);

//         root->right = helper(inorder , postorder , valueIdx+1 , end , idx);
//         root->left = helper(inorder , postorder , start , valueIdx-1 , idx);

//         return root;
//     }

//     TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//         int n = postorder.size();

//         int idx = n-1;

//         return helper(inorder , postorder , 0 , n-1 , idx);
//     }
// };







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
//Recursion:
class Solution {
public:

    TreeNode* helper(vector<int>& inorder , vector<int>& postorder , int start , int end , int &idx){
        if(idx < 0 || start > end) return NULL;

        int rootVal = postorder[idx];

        int i;
        for(i=start; i<=end; i++){
            if(inorder[i] == rootVal){
                break;
            }
        }
        idx--;

        TreeNode* root = new TreeNode(rootVal);

        root->right = helper(inorder , postorder , i+1 , end , idx);
        root->left = helper(inorder , postorder , start , i-1 , idx);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();

        int idx = n-1;

        return helper(inorder , postorder , 0 , n-1 , idx);
    }
};