class Solution {
public:

    bool isPalindrome(string str , int i , int j){
        i = 0;
        j = str.size()-1;

        while(i < j){
            if(str[i++] != str[j--]){
                return false;
            }
        }
        return true;
    }

    void recursion(int idx , string &s , vector<string> &temp , vector<vector<string>> &ans){
        if(idx == s.size()){
            ans.push_back(temp);
            return;
        }
        
        string str;
        for(int i=idx; i<s.size(); i++){
            str += s[i];
            if(isPalindrome(str , idx , i)){
                temp.push_back(str);
                recursion(i+1 , s , temp , ans);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();

        vector<string> temp;
        vector<vector<string>> ans;

        recursion(0 , s , temp , ans);

        return ans;
    }
};