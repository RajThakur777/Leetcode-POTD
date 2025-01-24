class Solution {
public:

    void recursion(int idx , vector<int>& nums , int target , int sum , int &cnt){
        if(idx == nums.size()){
            if(sum == target){
                cnt++;
            }
            return;
        }

        recursion(idx+1 , nums , target , sum + nums[idx] , cnt);

        recursion(idx+1 , nums , target , sum - nums[idx] , cnt);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        int cnt = 0;

        recursion(0 , nums , target , 0 , cnt);

        return cnt;
    }
};