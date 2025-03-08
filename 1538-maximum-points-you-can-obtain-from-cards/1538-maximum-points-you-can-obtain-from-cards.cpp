class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        int len = n-k;

        int i = 0;
        int sum = 0;

        int total = 0;
        int ans = INT_MAX;

        for(int i=0; i<n; i++) total += cardPoints[i];

        int l = 0;
        for(int j=0; j<n; j++){
            sum += cardPoints[j];

            while((j - i + 1) > len){
                sum -= cardPoints[i];
                i++;
            }

            if((j - i + 1) == len){
                ans = min(ans , sum);
            }
        }
        return total - ans;
    }
};