class Solution {
public:
    bool isPossible(int mid , vector<int> &nums , int k) {
        int split = 1;
        int sum = 0;

        for(int i=0; i<nums.size(); i++) {
            if(sum + nums[i] <= mid) {
                sum += nums[i];
            }
            else {
                split++;
                sum = nums[i];
            }

            if(split > k) return false;
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) { 
        int n = nums.size();

        int low = *max_element(nums.begin() , nums.end());
        int high = accumulate(nums.begin() , nums.end() , 0);

        int ans = -1;

        while(low <= high) {
            int mid = low + ((high - low) / 2);

            if(isPossible(mid , nums , k)) {
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