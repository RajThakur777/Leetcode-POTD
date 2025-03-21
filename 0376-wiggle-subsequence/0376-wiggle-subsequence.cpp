class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();

        if(nums.size() < 2) return nums.size();

        int cnt = 0;

        int prevDiff = nums[1] - nums[0];

        if(prevDiff != 0){
            cnt = 2;
        }
        else {
            cnt = 1;
        }

        for(int i=2; i<n; i++){
            int curr = nums[i] - nums[i-1];

            if((curr > 0 && prevDiff <= 0) || (curr < 0 && prevDiff >= 0)){
                cnt++;
                prevDiff = curr;
            }
        }
        return cnt;
    }
};