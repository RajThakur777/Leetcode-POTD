class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int , int> mpp;
        for(int i=0; i<n; i++) {
            mpp[nums[i]]++;
        }

        vector<int> ans;
        for(auto it : mpp) {
            if(it.second > 1) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};