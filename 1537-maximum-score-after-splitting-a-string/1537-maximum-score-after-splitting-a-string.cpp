//Brute force:
class Solution {
public:
    int maxScore(string s) {   
        int n = s.size();

        int maxScore = INT_MIN;

        for(int i=0; i<n-1; i++){
            int zero = 0;
            int one = 0;
            
            for(int left=0; left<=i; left++){
                if(s[left] == '0'){
                    zero++;
                }
            }

            for(int right=i+1; right<=n; right++){
                if(s[right] == '1'){
                    one++;
                }
            }
            maxScore = max(maxScore , zero + one);
        }
        return maxScore;
    }
};