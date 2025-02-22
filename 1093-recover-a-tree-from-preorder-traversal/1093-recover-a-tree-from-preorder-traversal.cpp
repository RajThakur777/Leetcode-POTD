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

    TreeNode* helper(int &idx , string &traversal , int depth){
        int n = traversal.size();

        if(idx >= traversal.size()) return NULL;

        //calculate dash
        int j = idx;
        while(j < n && traversal[j] == '-'){
            j++;
        }
        int dash = j-idx;

        if(depth != dash){
            return NULL;
        }

        idx += dash;

        //calculate number;
        int num = 0;
        while(idx < n && isdigit(traversal[idx])){
            num = (num * 10) + (traversal[idx] - '0');
            idx++;
        }

        TreeNode* curr = new TreeNode(num);
        curr->left = helper(idx , traversal , depth + 1);
        curr->right = helper(idx , traversal , depth + 1);

        return curr;
    }

    TreeNode* recoverFromPreorder(string traversal) { 
        int idx = 0;

        return helper(idx , traversal , 0);  
    }
};