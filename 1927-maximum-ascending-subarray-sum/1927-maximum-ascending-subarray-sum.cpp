class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();

        int maxi = *max_element(nums.begin() , nums.end());

        for(int i=0; i<n; i++){
            int sum = nums[i];
            for(int j=i+1; j<n; j++){
                if(nums[j] > nums[j-1]){
                    sum += nums[j];
                    maxi = max(maxi , sum);
                }
                else {
                    sum = 0;
                    break;
                }
            }
        }
        return maxi;
    }
};