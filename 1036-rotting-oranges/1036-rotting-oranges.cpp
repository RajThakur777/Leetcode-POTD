//Multi-Source BFS Algo:
class Solution {
public:

    vector<vector<int>> directions = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}};

    bool is_Safe(int x , int y , vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();

        return (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1);
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int fresh = 0;
        int time = 0;

        queue<pair<int , int>> q;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 2) {
                    q.push({i , j});
                }
                else if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        if(fresh == 0) return 0;

        while(!q.empty()) {
            int sz = q.size();

            while(sz--) {
                int x = q.front().first;
                int y = q.front().second;

                q.pop();

                for(auto &dir : directions) {
                    int x_ = x + dir[0];
                    int y_ = y + dir[1];

                    if(is_Safe(x_ , y_ , grid)) {
                        grid[x_][y_] = 2;
                        q.push({x_ , y_});
                        fresh--;
                    }
                }
            }
            time++;
        }
        return (fresh == 0 ? time - 1 : -1);
    }
};