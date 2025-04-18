class Solution {
public:

    string helper(int idx , string ans , int n){
        if(idx == n) return ans;

        string temp;
        int cnt = 1;
        for(int i=1; i<ans.size(); i++) {
            if(ans[i] == ans[i-1]){
                cnt++;
            }
            else {
                temp += to_string(cnt);
                temp += ans[i-1];
                cnt = 1;
            }
        }
        temp += to_string(cnt);
        temp += ans[ans.size() - 1];

        return helper(idx+1 , temp , n);
    }

    string countAndSay(int n) {
        string ans = "1";

        return helper(1 , ans , n);
    }
};