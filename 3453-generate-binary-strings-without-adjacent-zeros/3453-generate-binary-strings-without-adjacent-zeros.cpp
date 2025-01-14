class Solution {
public:

    void recursion(int n , vector<string> &ans , string s){
        if(n == 0){
            ans.push_back(s);
            return;
        }

        if(s.empty() || s.back() == '1'){
            recursion(n-1 , ans , s + '0');
            recursion(n-1 , ans , s + '1');
        }
        else {
            recursion(n-1 , ans , s + '1');
        }
    }

    vector<string> validStrings(int n) {
        vector<string> ans;
        
        string s;

        recursion(n , ans , s);

        return ans;
    }
};