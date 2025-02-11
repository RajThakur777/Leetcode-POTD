class Solution {
public:

    void helper(int idx , int n , int numOpen , string curr , vector<string> &ans){
        if(idx == n){
            if(numOpen == 0){
                ans.push_back(curr);
            }
            return;
        }

        helper(idx+1 , n , numOpen+1 , curr + "(" , ans);
        if(numOpen){
            helper(idx+1 , n , numOpen-1, curr+")" , ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        helper(0 , 2*n , 0 , "" , ans);

        return ans;
    }
};
