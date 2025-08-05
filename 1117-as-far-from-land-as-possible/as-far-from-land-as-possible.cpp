//Multi-source BFS:
class Solution {
public:
    int n;

    vector<vector<int>> directions = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}};

    int maxDistance(vector<vector<int>>& grid) { 
        n = grid.size();

        queue<pair<int , int>> q;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    q.push({i , j});
                }
            }
        }

        int level = 0;

        while(!q.empty()) {
            int sz = q.size();

            while(sz--) {
                int x = q.front().first;
                int y = q.front().second;

                q.pop();

                for(auto dir : directions) {
                    int x_ = x + dir[0];
                    int y_ = y + dir[1];

                    if((x_ >= 0 && x_ < n && y_ >= 0 && y_ < n) && (grid[x_][y_] == 0)) {
                        q.push({x_ , y_});
                        grid[x_][y_] = 1;
                    }
                }
            }
            level++;
        }
        if(level == 1) return -1;

        return level - 1;
    }
};