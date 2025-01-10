class Solution {
public:

    void recursion(vector<int> &res , int idx , vector<int> &temp , vector<vector<int>> &ans){
        if(idx == res.size()){
            ans.push_back(temp);
            return;
        }

        //take
        temp.push_back(res[idx]);
        recursion(res , idx + 1 , temp , ans);
        temp.pop_back();

        //not-take
        recursion(res , idx + 1 , temp , ans);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> res;
        for(int i=1; i<=n; i++){
            res.push_back(i);
        }

        vector<int> temp;
        vector<vector<int>> ans;

        recursion(res , 0 , temp  , ans);

        vector<vector<int>> final;

        for(const auto &subset : ans){
            if(subset.size() == k){
                final.push_back(subset);
            }
        }
        return final;
    }
};