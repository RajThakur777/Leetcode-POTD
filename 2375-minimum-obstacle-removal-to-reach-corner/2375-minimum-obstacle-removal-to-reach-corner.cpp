//Dijktra's Algorithm:
class Solution {
public:

    vector<vector<int>> directions = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}};

    typedef pair<int , pair<int , int>> P;

    bool is_Safe(int x , int y , vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();

        return (x >= 0 && x < m && y >= 0 && y < n);
    }

    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dist(m , vector<int>(n , INT_MAX));
        dist[0][0] = grid[0][0];

        priority_queue<P , vector<P> , greater<P>> pq;
        pq.push({0 , {0 , 0}});

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int d = it.first;
            int x = it.second.first;
            int y = it.second.second;

            if(x == m-1 && y == n-1) return d;

            for(auto &dir : directions) {
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                if(is_Safe(x_ , y_ , grid) && (d + grid[x_][y_]) < dist[x_][y_]) {
                    dist[x_][y_] = d + grid[x_][y_];
                    pq.push({d + grid[x_][y_] , {x_ , y_}});
                }
            }
        }
        return dist[m-1][n-1];
    }
};