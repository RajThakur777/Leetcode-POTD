class Solution {
public:

    int isCnt(int x){
        int res = 0;

        while(x > 0){
            x = x / 10;
            res++;
        }
        return res;
    }

    int findNumbers(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;

        for(int i=0; i<n; i++){
            if(isCnt(nums[i]) % 2 == 0){
                ans++;
            }
        }
        return ans;
    }
};