//Recursion:
class Solution {
public:

    bool check(string &s , int i , int j) {
        if(i > j) return true;

        if(s[i] == s[j]) {
            return check(s , i+1 , j-1);
        }
        return false;
    }

    string longestPalindrome(string s) {
        int n = s.size();

        string ans;

        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                if(check(s , i , j)){
                    if((j-i+1) > ans.size()) {
                        ans = s.substr(i , j-i+1);
                    }
                }
            }
        }
        return ans;
    }
};