//Using Two Hashmaps:
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();

        vector<int> ans(n);

        unordered_map<int , int> mpp1;
        unordered_map<int , int> mpp2;

        for(int i=0; i<n; i++){
            int ball = queries[i][0];
            int color = queries[i][1];

            if(mpp1.find(ball) != mpp1.end()){
                int prev = mpp1[ball];
                mpp2[prev]--;

                if(mpp2[prev] == 0){
                    mpp2.erase(prev);
                }
            }
            mpp1[ball] = color;
            mpp2[color]++;

            ans[i] = mpp2.size();
        }
        return ans;
    }
};
