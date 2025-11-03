class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();

        int ans = 0;

        for(int i=0; i<n; i++) {
            char color = colors[i];
            int j = i;

            int maxi = 0;
            int sum = 0;

            while(j < n && colors[j] == color) {
                maxi = max(maxi , neededTime[j]);
                sum += neededTime[j];
                j++;
            }

            i = j - 1;

            ans += (sum - maxi);
        }
        return ans;
    }
};