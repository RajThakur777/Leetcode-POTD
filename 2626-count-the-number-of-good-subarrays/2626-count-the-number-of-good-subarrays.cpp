class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();

        long long cnt = 0;

        long long res = 0;

        map<long long , long long> mpp;

        int i = 0;
        for(int j=0; j<n; j++){
            res += mpp[nums[j]];

            mpp[nums[j]]++;

            while(res >= k){
                cnt += (n - j);

                mpp[nums[i]]--;

                res -= mpp[nums[i]];

                i++;
            }
        }
        return cnt;
    }
};