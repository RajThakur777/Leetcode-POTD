class Solution {
public:

    void helper(int idx , string s , vector<string>&res , string curr){
        if(idx == s.size()){
            res.push_back(curr);
            return;
        }

        //digit
        if(isdigit(s[idx])){
            curr += s[idx];
            helper(idx+1 , s , res , curr);
        }
        else {
            //character
            curr += tolower(s[idx]);
            helper(idx+1 , s , res , curr);
            curr.pop_back();

            curr += toupper(s[idx]);
            helper(idx+1 , s , res , curr);
            curr.pop_back();
        }
    }

    vector<string> letterCasePermutation(string s) {
        vector<string> res;

        string curr = "";

        helper(0 , s , res , curr);

        return res; 
    }
};