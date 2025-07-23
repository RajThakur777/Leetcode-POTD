class Solution {
public:
    int m;
    int n;

    vector<vector<int>> directions = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}};

    bool is_Safe(int x , int y) {
        return (x >= 0 && x < m && y >= 0 && y < n);
    }

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        m = isWater.size();
        n = isWater[0].size();


        vector<vector<int>> ans(m , vector<int>(n , -1));

        queue<pair<int , int>> q;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(isWater[i][j] == 1) {
                    ans[i][j] = 0;
                    q.push({i , j});
                }
            }
        }

        while(!q.empty()) {
            int sz = q.size();

            while(sz--) {
                int x = q.front().first;
                int y = q.front().second;

                q.pop();

                for(auto &dir : directions) {
                    int x_ = x + dir[0];
                    int y_ = y + dir[1];

                    if(is_Safe(x_ , y_) && ans[x_][y_] == -1) {
                        ans[x_][y_] = 1 + ans[x][y];
                        q.push({x_ , y_});
                    }
                }
            }
        }
        return ans;
    }
};