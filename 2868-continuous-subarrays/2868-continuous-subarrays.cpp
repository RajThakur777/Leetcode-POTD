class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();

        long long cnt = 0;

        map<int , int> mpp;

        int i = 0;
        for(int j=0; j<n; j++) {
            mpp[nums[j]]++;

            while(abs(mpp.rbegin()->first  - mpp.begin()->first) > 2){
                mpp[nums[i]]--;
                if(mpp[nums[i]] == 0) mpp.erase(nums[i]);
                i++;
            }

            cnt += (j - i + 1);
        }
        return cnt;
    }
};