class Solution {
public:
    void solve(int idx , int k , int n , vector<vector<int>> &res , vector<int> &temp) {
        if(k == 0 && n == 0) {
            res.push_back(temp);
            return;
        }

        if(idx > 9) return;

        if(k <= 0 || n <= 0) return;

        //pick:
        if(idx <= n) {
            temp.push_back(idx);
            solve(idx+1 , k-1 , n-idx , res , temp);
            temp.pop_back();
        }        

        //not_pick
        solve(idx+1 , k , n , res , temp);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;

        vector<int> temp;

        solve(1 , k , n , res , temp);

        return res;
    }
};