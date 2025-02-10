class Solution {
public:
    vector<int> numbers = {1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9};

    void helper(int idx , int k , int cnt , vector<vector<int>> &ans , vector<int> &res , int n){
        if(n == 0){
            if(cnt == k){
                ans.push_back(res);
            }
            return;
        }

        if(idx == numbers.size()) return;

        //pick
        if(numbers[idx] <= n){
            res.push_back(numbers[idx]);
            helper(idx+1 , k , cnt+1 , ans , res , n-numbers[idx]);
            res.pop_back();
        }

        //not-pick
        helper(idx+1 , k , cnt , ans , res , n);
    }

    vector<vector<int>> combinationSum3(int k, int n) { 
        vector<vector<int>> ans;
        vector<int> res;

        int cnt = 0;

        helper(0 , k , cnt , ans , res , n);

        return ans;
    }
};