class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();

        int cnt = 0;

        for(int i=0; i<n; i++) {
            if(nums[i] == 0) {
                int sum1 = 0;
                int sum2 = 0;

                for(int j1=0; j1<=i; j1++) {
                    sum1 += nums[j1];
                }

                for(int j2=i; j2<n; j2++) {
                    sum2 += nums[j2];
                }

                if(abs(sum1 - sum2) == 0) {
                    cnt += 2;
                }
                else if(abs(sum1 - sum2) == 1) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};