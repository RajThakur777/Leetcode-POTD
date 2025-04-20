class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int n = nums.size();

        if(is_sorted(nums.begin() , nums.end())){
            return nums.size();
        }

        int maxi = nums[0];
        int cnt = 0;
        for(int i=1; i<n; i++){
            if(nums[i] < maxi){
                cnt++;
            }
            else {
                maxi = max(maxi , nums[i]);
            }
        }
        return n - cnt;
    }
};