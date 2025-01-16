class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i = 0;
        int j = nums.size();
         
        sort(nums.begin() , nums.end());

        while(i < j){
            int mid = (i + j) / 2;

            if(nums[mid] > mid){
                j = mid;
            }
            else {
                i = mid+1;
            }
        } 
        return i;
    }
};