class Solution {
public:

    void recursion(vector<int> &nums , int idx , vector<int> &temp , set<vector<int>> &ans){
        if(idx == nums.size()){
            if(temp.size() >= 2){
                ans.insert(temp);
            }
            return;
        }

        //pick
        if(!temp.size() || nums[idx] >= temp.back()){
            temp.push_back(nums[idx]);
            recursion(nums , idx + 1 , temp , ans);
            temp.pop_back();
        }

        //not-pick
        recursion(nums , idx + 1 , temp , ans);
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> temp;

        recursion(nums , 0 , temp , ans);

        return vector(ans.begin() , ans.end());
    }
};