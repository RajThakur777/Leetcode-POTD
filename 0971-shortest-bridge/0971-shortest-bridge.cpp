//DFS + BFS:
class Solution {
public:
    int m;
    int n;

    vector<vector<int>> directions = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}};

    bool is_Safe(int x , int y , vector<vector<int>> &grid) {
        m = grid.size();
        n = grid[0].size();

        return (x >= 0 && x < m && y >= 0 && y < n);
    }

    void dfs(int i , int j , vector<vector<int>> &grid) {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1) return;

        grid[i][j] = 2;

        dfs(i - 1 , j , grid);
        dfs(i + 1 , j , grid);
        dfs(i , j - 1 , grid);
        dfs(i , j + 1 , grid);
    }

    int shortestBridge(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        bool flag = false;

        int c = 1;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1 && c > 0) {
                    dfs(i , j , grid);
                    c--;
                    break;
                }
            }
            if(c == 0) break; 
        }

        queue<pair<int , int>> q;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 2) {
                    q.push({i , j});
                }
            }
        }

        int cnt = 0;

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
                        if(grid[x_][y_] == 1) return cnt;

                        if(grid[x_][y_] == 0) {
                            grid[x_][y_] = 2;
                            q.push({x_ , y_});
                        }
                    }
                }
            }
            cnt++;
        }
        return -1;
    }
};
