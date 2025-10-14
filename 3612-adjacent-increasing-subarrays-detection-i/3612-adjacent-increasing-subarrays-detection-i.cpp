class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        bool flag = false;

        if(k == 1) return true;

        for(int i=0; i<n; i++) {
            int j = i;
            while(j < n - 1 && nums[j] < nums[j+1]) {
                j++;

                if((j - i + 1) == k) {
                    int l = j + 1;
                    j++;
                    while(l < n - 1 && nums[l] < nums[l+1]) {
                        l++;

                        if((l - j + 1) == k) {
                           flag = true;
                           break;
                        }
                    }
                }
                if(flag) break;
            }
            if(flag) break;
        }
        return flag;
    }
};