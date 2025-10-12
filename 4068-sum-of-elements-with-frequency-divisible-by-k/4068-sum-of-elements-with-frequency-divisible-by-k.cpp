class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        map<int , int> mpp;

        for(int i=0; i<nums.size(); i++) {
            mpp[nums[i]]++;
        }

        int sum = 0;

        for(auto it : mpp) {
            if(it.second % k == 0) {
                sum += (it.second * it.first);
            }
        }
        return sum;
    }
};