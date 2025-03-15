class Solution {
public:

    bool isPossible(int mid , vector<int> &nums , int maxOperations){
        int cnt = 0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] > mid){
                cnt += (nums[i] - 1) / mid;
            }

            if(cnt > maxOperations) return false;
        }
        return true;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int n = nums.size();

        int low = 1;
        int high = *max_element(nums.begin() , nums.end());

        int ans = 0;

        while(low <= high){
            int mid = (low + high) / 2;

            if(isPossible(mid , nums , maxOperations)){
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