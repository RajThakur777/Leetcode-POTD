class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int n = nums.size();

        map<int , int> mpp;
        for(int i=0; i<n; i++) mpp[nums[i]]++;

        int xr = 0;
        for(auto it : mpp){
            if(it.second >= 2){
                xr ^= it.first;
            }
        }
        return xr;
    }
};