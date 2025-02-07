class Solution {
public:

    int cntDigits(int n){
        int cnt = 0;
        while(n > 0){
            n = n / 10;
            cnt++;
        }
        return cnt;
    }

    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            if(cntDigits(nums[i]) % 2 == 0){
                ans++;
            }
        }
        return ans;
    }
};