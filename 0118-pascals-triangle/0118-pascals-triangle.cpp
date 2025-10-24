class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);

        ans[0] = {1};
        if(numRows > 1) {
            ans[1] = {1 , 1};
        }

        for(int i=2; i<numRows; i++) {
            vector<int> prev = ans[i-1];

            vector<int> res;
            res.push_back(1);

            for(int i=0; i<prev.size()-1; i++) {
                res.push_back(prev[i] + prev[i+1]);
            }

            res.push_back(1);

            ans[i] = res;
        }
        return ans;
    }
};