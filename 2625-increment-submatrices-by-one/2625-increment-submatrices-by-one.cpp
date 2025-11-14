class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        int sz = queries.size();

        vector<vector<int>> grid(n , vector<int>(n , 0));

        for(int i=0; i<sz; i++) {
            int r1 = queries[i][0];
            int c1 = queries[i][1];
            int r2 = queries[i][2];
            int c2 = queries[i][3];

            for(int k1=r1; k1<=r2; k1++) {
                for(int k2=c1; k2<=c2; k2++) {
                    grid[k1][k2] += 1;
                }
            }
        }
        return grid;
    }
};