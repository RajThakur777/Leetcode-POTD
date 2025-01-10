class Solution {
public:

    void recursion(vector<int> &nums , int idx , int sum , int target , int &cnt){
        if(idx == nums.size()){
            if(sum == target){
                cnt++;
            }
            return;
        }

        recursion(nums , idx + 1 , sum + nums[idx] , target , cnt);

        recursion(nums , idx + 1 , sum - nums[idx] , target , cnt);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        
        int cnt = 0;

        int sum = 0;

        recursion(nums , 0 , sum , target , cnt);

        return cnt;
    }
};