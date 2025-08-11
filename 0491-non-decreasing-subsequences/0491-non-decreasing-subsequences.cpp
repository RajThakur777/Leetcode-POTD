class Solution {
public:
    void solve(int idx , vector<vector<int>> &ans , vector<int> &temp , vector<int> &nums) {
        if(idx == nums.size()) {
            if(temp.size() >= 2) {
                if(find(ans.begin() , ans.end() , temp) == ans.end()) {
                    ans.push_back(temp);
                }
            }
            return;
        }

        //take
        if(temp.size() == 0 || temp.back() <= nums[idx]) {
            temp.push_back(nums[idx]);
            solve(idx+1 , ans , temp , nums);
            temp.pop_back();
        }

        //not_take
        solve(idx+1 , ans , temp , nums);
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> ans;
        vector<int> temp;

        solve(0 , ans , temp , nums);

        return ans;
    }
};