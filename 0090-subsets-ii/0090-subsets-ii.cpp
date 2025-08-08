class Solution {
public:

    void solve(int idx , vector<int> &nums , vector<int> &temp , vector<vector<int>> &res) {
        if(idx >= nums.size()) {
            res.push_back(temp);
            return;
        }

        //take
        temp.push_back(nums[idx]);
        solve(idx+1 , nums , temp , res);

        int i = idx + 1;
        while(i < nums.size() && nums[i] == nums[i-1]) {
            i++;
        }

        //not_take
        temp.pop_back();
        solve(i , nums , temp , res);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin() , nums.end());

        vector<vector<int>> res;

        vector<int> temp;

        solve(0 , nums , temp , res);

        return res;
    }
};