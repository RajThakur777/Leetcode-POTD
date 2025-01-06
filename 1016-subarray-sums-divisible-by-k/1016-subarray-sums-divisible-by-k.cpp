class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();

        map<int , int> mpp;
        int cnt = 0;

        int sum = 0;
        mpp[0] = 1;
        for(int i=0; i<n; i++){
            sum += nums[i];

            int rem = sum%k;
            if(rem < 0) rem += k;

            if(mpp.find(rem) != mpp.end()){
                cnt += mpp[rem];
            }

            mpp[rem]++;
        }   
        return cnt;
    }
};