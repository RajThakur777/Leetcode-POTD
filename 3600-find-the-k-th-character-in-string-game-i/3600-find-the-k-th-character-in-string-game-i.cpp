class Solution {
public:

    string recursion(string ans , int k) {
        if(ans.size() >= k) return ans;

        string res = ans;

        for(int i=0; i<ans.size(); i++) {
            res += ((ans[i] - 'a' + 1) % 26 + 'a');
        }
        return recursion(res , k);
    } 

    char kthCharacter(int k) {
        string ans = recursion("a" , k);

        return ans[k-1];
    }
};







