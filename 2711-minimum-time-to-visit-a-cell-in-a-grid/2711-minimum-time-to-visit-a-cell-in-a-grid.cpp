//Dijiktra's Algo:
class Solution {
public:

    vector<vector<int>> directions = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}};

    typedef pair<int , pair<int , int>> P;

    int minimumTime(vector<vector<int>>& grid) { 
        int m = grid.size();
        int n = grid[0].size();

        if (grid[0][1] > 1 && grid[1][0] > 1)
            return -1;
        
        vector<vector<bool>> visited(m , vector<bool>(n , false));

        vector<vector<int>> dist(m , vector<int>(n , INT_MAX));

        priority_queue<P , vector<P> , greater<P>> pq;
        pq.push({grid[0][0] , {0 , 0}});

        dist[0][0] = 0;

        while(!pq.empty()) {
            int time = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;

            pq.pop();

            if(x == m-1 && y == n-1) return dist[x][y];

            if(visited[x][y] == true) continue;

            visited[x][y] = true;

            for(auto &dir : directions) {
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                if(x_ < 0 || x_ >= m || y_ < 0 || y_ >= n || visited[x_][y_]) continue;

                if((time + 1) >= grid[x_][y_]) {
                    dist[x_][y_] = time + 1;
                    pq.push({time+1 , {x_ , y_}});
                }
                else if((grid[x_][y_] - time) % 2 == 0) {
                    dist[x_][y_] = grid[x_][y_] + 1;
                    pq.push({grid[x_][y_] + 1 , {x_ , y_}}); 
                }
                else {
                    dist[x_][y_] = grid[x_][y_];
                    pq.push({grid[x_][y_] , {x_ , y_}}); 
                }
            }
        }
        return -1;
    }
};