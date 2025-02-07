class Solution {
public:

    void helper(int n , vector<string> &ans , string res){
        if(n == 0){
            ans.push_back(res);
            return;
        }

            //take-1
        if(res.empty() || res.back() == '1'){
            helper(n-1 , ans , res+'1');
            helper(n-1 , ans , res+'0');
        }
        else {
            //take-0
            helper(n-1 , ans , res+'1');
        }
    }

    vector<string> validStrings(int n) {
        vector<string> ans;

        string res;

        helper(n , ans , res);

        return ans;
    }
};