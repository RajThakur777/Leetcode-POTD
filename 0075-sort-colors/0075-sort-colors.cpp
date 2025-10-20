class Solution {
public:
    void sortColors(vector<int>& nums) {   
        int n = nums.size();   

        int cnt_0 = 0;
        int cnt_1 = 0;
        int cnt_2 = 0;

        for(int i=0; i<n; i++) {
            if(nums[i] == 0) {
                cnt_0++;
            }
            else if(nums[i] == 1) {
                cnt_1++;
            }
            else {
                cnt_2++;
            }
        }

        int idx = 0;
        while(cnt_0--) {
            nums[idx] = 0;
            idx++;
        }

        while(cnt_1--) {
            nums[idx] = 1;
            idx++;
        }

        while(cnt_2--) {
            nums[idx] = 2;
            idx++;
        }
    }
};