class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string ans = "";

        while(a > 0 || b > 0){
            if(ans.size() >= 2 && ans.back() == ans[ans.size() - 2]){
                if(ans.back() == 'a'){
                    ans += 'b';
                    b--;
                }
                else {
                    ans += 'a';
                    a--;
                }
            }
            else {
                if(a >= b){
                    ans += 'a';
                    a--;
                }
                else {
                    ans += 'b';
                    b--;
                }
            }
        }
        return ans;
    }
};