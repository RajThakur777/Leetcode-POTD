class Solution {
public:

    int solve(vector<int> &nums , int k){
        int n = nums.size();

        for(int i=0; i<n; i++){
            if(nums[i] % 2 == 0){
                nums[i] = 0;
            }
            else {
                nums[i] = 1;
            }
        }

        int cnt = 0;
        int i = 0;
        int sum = 0;

        for(int j=0; j<n; j++){
            sum += nums[j];

            while(sum > k){
                sum -= nums[i];
                i++;
            }

            cnt += (j - i + 1);
        }
        return cnt;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums , k) - solve(nums , k-1);
    }
};