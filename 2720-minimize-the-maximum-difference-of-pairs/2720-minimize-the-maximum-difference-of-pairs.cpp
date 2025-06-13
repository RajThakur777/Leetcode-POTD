class Solution {
public:

    bool isPoss(int mid , vector<int>& nums , int p) {
        int cnt = 0;

        int i = 0;

        while(i < nums.size() - 1) {
            if(nums[i+1] - nums[i] <= mid){
                cnt++;
                i += 2;
            }
            else {
                i++;
            }
        }
        return cnt >= p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();

        sort(nums.begin() , nums.end());

        int l = 0;
        int r = *max_element(nums.begin() , nums.end()) - *min_element(nums.begin() , nums.end());

        int ans = 0;

        while(l <= r){
            int mid = (l + r) / 2;

            if(isPoss(mid , nums , p)){
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }
};