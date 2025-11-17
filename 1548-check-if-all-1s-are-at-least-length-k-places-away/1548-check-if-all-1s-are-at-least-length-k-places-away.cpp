class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();

        bool flag = true;

        int last = 0;

        for(int i=0; i<n; i++) {
            if(nums[i] == 1) {
                last = i;
                break;
            }
        }

        for(int i=last+1; i<n; i++) {
            if(nums[i] == 1) {
                if(i - last - 1 < k) {
                    flag = false;
                    break;
                }
                else {
                    last = i;
                }
            }
        }
        return flag;
    }
};