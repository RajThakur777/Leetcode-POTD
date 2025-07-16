class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();

        for(int i=0; i<n; i++) {
            nums[i] = (nums[i] % 2);
        }

        int cnt_0 = 0;
        int cnt_1 = 0;
        for(int i=0; i<n; i++) {
            if(nums[i] == 0) {
                cnt_0++;
            }
            else {
                cnt_1++;
            }
        }

        int res = max(cnt_0  , cnt_1);

        int idx1 = 0;
        for(int i=0; i<n; i++) {
            if(nums[i] == 1) {
                idx1 = i;
                break;
            }
        }

        int ans1 = 1;
        int prev1 = 1;

        for(int i=idx1+1; i<n; i++) {
            if(nums[i] != prev1) {
                ans1++;
                prev1 = 1 - prev1;
            }
        }

        int idx2 = 0;
        for(int i=0; i<n; i++) {
            if(nums[i] == 0) {
                idx2 = i;
                break;
            }
        }

        int ans2 = 1;
        int prev2 = 0;

        for(int i=idx2+1; i<n; i++) {
            if(prev2 != nums[i]) {
                ans2++;
                prev2 = 1 - prev2;
            }
        }
        int v = max(ans1 , ans2);

        return max(v , res);
    }
};