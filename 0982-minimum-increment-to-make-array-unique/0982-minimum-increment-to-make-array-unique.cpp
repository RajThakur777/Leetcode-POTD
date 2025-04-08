class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());

        int prev = nums[0];

        int cnt = 0;
        for(int i=1; i<n; i++){
            if(nums[i] == prev){
                cnt++;
                nums[i]++;
                prev = nums[i];
            }
            else if(nums[i] < prev){
                cnt += abs(nums[i] - prev) + 1;
                nums[i] += (abs(nums[i] - prev) + 1);
                prev = nums[i];
            }
            else {
                prev = nums[i];
            }
        }
        return cnt;
    }
};