class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {  
        int n = nums.size();

        long long cnt = 0;  

        sort(nums.begin() , nums.end());

        for(int i=0; i<n; i++){
            int idx1 = lower_bound(nums.begin() + i + 1 , nums.end() ,  lower - nums[i]) - nums.begin();
            int idx2 = upper_bound(nums.begin() + i + 1 , nums.end() , upper - nums[i]) - nums.begin();

            cnt += (idx2 - idx1);
        }
        return cnt;
    }
};