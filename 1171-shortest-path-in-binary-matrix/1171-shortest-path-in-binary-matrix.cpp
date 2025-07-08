//BFS:
class Solution {
public:

    vector<vector<int>> directions = {{1 , 1} , {0 , 1} , {1 , 0} , {-1 , 0} , {0 , -1} , {-1 , -1} , {1 , -1} , {-1 , 1}};


    bool isSafe(int x , int y , vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        return (x >= 0 && x < m && y >= 0 && y < n);
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if(m == 0 || n == 0 || grid[0][0] != 0) return -1;

        queue<pair<int , int>> q;
        q.push({0 , 0});
        grid[0][0] = 1;

        int cnt = 0;

        while(!q.empty()) {
            int N = q.size();

            while(N--) {
                auto it = q.front();
                q.pop();

                int x_ = it.first;
                int y_ = it.second;

                if(x_ == m-1 && y_ == n-1) return cnt + 1;

                for(auto &dir : directions) {
                    int x = x_ + dir[0];
                    int y = y_ + dir[1];

                    if(isSafe(x , y , grid) && grid[x][y] == 0) {
                        grid[x][y] = 1;
                        q.push({x , y});
                    }
                }
            }
            cnt++;
        }
        return -1;
    }
};