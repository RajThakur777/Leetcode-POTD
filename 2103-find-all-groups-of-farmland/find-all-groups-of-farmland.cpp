class Solution {
public:

    vector<vector<int>> directions = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}};

    int m;
    int n;

    void dfs(int i , int j , vector<vector<int>>& land , vector<int> &v) {
        if(i < 0 || i >= m || j < 0 || j >= n || land[i][j] == 0) return;

        land[i][j] = 0;
        v[0] = max(v[0] , i);
        v[1] = max(v[1] , j);

        for(auto &dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            dfs(i_ , j_ , land , v);
        }
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;

        m = land.size();
        n = land[0].size();

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                vector<int> res;
                vector<int> v(2);
                if(land[i][j] == 1) {
                    res.push_back(i);
                    res.push_back(j);
                    dfs(i , j , land , v);
                    res.push_back(v[0]);
                    res.push_back(v[1]);
                    ans.push_back(res);
                }
            }
        }
        return ans;
    }
};