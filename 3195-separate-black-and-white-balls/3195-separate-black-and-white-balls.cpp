class Solution {
public:
    long long minimumSteps(string s) {   
        int n = s.size();

        long long one = 0;
        long long ans = 0;

        for(int i=0; i<n; i++){
            if(s[i] == '0'){
                ans += one;
            }
            else {
                one++;
            }
        }
        return ans;
    }
};