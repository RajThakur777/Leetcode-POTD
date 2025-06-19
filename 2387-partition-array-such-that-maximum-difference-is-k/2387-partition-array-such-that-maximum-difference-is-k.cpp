class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin() , nums.end());

        int cnt = 0;

        int idx = -1;

        for(int i=0; i<n; i++){
            int val = k + nums[i];

            idx = upper_bound(nums.begin() + i , nums.end() , val) - nums.begin();

            if(idx != -1) {
                cnt++;
                i = idx-1;
                idx = -1;
            }
        }
        return cnt;
    }
 };