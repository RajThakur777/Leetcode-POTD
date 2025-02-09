class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {   
        int n = values.size();

        int val1 = values[0];
        int ans = INT_MIN;

        for(int j=1; j<n; j++){
            int val2 = values[j] - j;
            ans = max(ans , val1 + val2);
            val1 = max(val1 , values[j] + j);
        }
        return ans;
    }
};