class Solution {
public:

    int solve(int idx , vector<int> &nums , int maxi , int curr) {
        if(idx == nums.size()) {
            if(curr == maxi) {
                return 1;
            }
            return 0;
        }

        int pick = solve(idx + 1 , nums , maxi , curr | nums[idx]);

        int not_pick = solve(idx + 1 , nums , maxi , curr);

        return pick + not_pick;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();

        int maxi = 0;
        for(int i=0; i<n; i++) {
            maxi |= nums[i];
        }

        return solve(0 , nums , maxi , 0);
    }
};