class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if((nums[i] % 2 != (i % 2)) && (nums[j] % 2 != (j % 2))){
                    swap(nums[i] , nums[j]);
                }
            }
        }
        return nums;
    }
};