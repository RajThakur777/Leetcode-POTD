class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();

        double maxi = INT_MIN;

        int i = 0;
        double sum = 0;

        for(int j=0; j<n; j++){
            sum += nums[j];

            while((j - i + 1) > k){
                sum -= nums[i];
                i++;
            }

            if((j - i + 1) == k){
                maxi = max(maxi , (sum / k));
            }
        }
        return maxi;
    }
};