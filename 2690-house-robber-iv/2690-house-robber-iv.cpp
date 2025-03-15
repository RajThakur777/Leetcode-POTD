class Solution {
public:

    bool isPossible(int mid , vector<int>& nums , int k){
        int cnt = 0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] <= mid){
                cnt++;
                i++;
            }
        }
        return cnt >= k;
    }

    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();

        int low = *min_element(nums.begin() , nums.end());
        int high = *max_element(nums.begin() , nums.end());

        int ans = 0;

        while(low <= high){
            int mid = (low + high) / 2;

            if(isPossible(mid , nums , k)){
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