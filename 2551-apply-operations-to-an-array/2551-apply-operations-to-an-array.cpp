class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();

        for(int i=0; i<n-1; i++){
            if(nums[i] == nums[i+1]){
                nums[i] = nums[i] * 2;
                nums[i+1] = 0;
            }
        }
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(nums[i] == 0 && nums[j] != 0){
                    swap(nums[i] , nums[j]);
                }
            }
        }

        return nums;
    }
};