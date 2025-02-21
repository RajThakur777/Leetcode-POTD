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
class FindElements {
public:
    set<int> st;

    void dfs(TreeNode* curr , int currValue){
        if(curr == nullptr) return;

        st.insert(currValue);
        dfs(curr->left , currValue*2 + 1);
        dfs(curr->right , currValue*2 + 2);
    }

    FindElements(TreeNode* root) {
        dfs(root , 0);
    }
    
    bool find(int target) {
        if(st.count(target)){
            return true;
        }
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */