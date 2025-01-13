class Solution {
public:

    void recursion(vector<int> &nums , int idx , vector<vector<int>> &ans , vector<int> &temp){
        if(idx == nums.size()){
            ans.push_back(temp);
            return;
        }

        //pick
        temp.push_back(nums[idx]);
        recursion(nums , idx + 1 , ans , temp);
        temp.pop_back();

        //not-pick
        recursion(nums , idx + 1 , ans , temp);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;

        recursion(nums , 0 , ans , temp); 

        return ans;
    }
};