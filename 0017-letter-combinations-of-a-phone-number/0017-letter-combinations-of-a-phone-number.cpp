class Solution {
public:
    string help[10] = {"" , "" , "abc" , "def" , "ghi" , "jkl"  , "mno" , "pqrs" , "tuv" , "wxyz"};

    void helper(int idx , string digits , string &ans , vector<string> &res){
        if(idx >= digits.size()){
            res.push_back(ans);
            return;
        }

        int digit = digits[idx] - '0';
        string temp = help[digit];
        
        for(int i=0; i<temp.size(); i++){
            ans.push_back(temp[i]);
            helper(idx+1 , digits , ans , res);
            ans.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};

        vector<string> res;

        string ans;

        helper(0 , digits , ans , res);

        return res;
    }
};