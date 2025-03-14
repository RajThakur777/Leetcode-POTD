class Solution {
public:

    bool isPossible(int mid , vector<int> &nums , int threshold){
        int cnt = 0;

        for(int i=0; i<nums.size(); i++){
            cnt += (nums[i] + mid - 1) / mid;
        }
        return cnt <= threshold;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();

        int low = 1;
        int high = *max_element(nums.begin() , nums.end());

        int ans = 0;

        while(low <= high){
            int mid = (low + high) / 2;

            if(isPossible(mid , nums , threshold)){
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};