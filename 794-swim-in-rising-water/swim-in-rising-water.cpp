//Dijiktra's Algorithm:
class Solution {
public:
    int n;

    vector<vector<int>> directions = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}};

    typedef pair<int , pair<int , int>> P;

    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();

        vector<vector<int>> dist(n , vector<int>(n , INT_MAX));

        priority_queue<P , vector<P> , greater<P>> pq;
        pq.push({grid[0][0] , {0 , 0}});
        dist[0][0] = 0;

        while(!pq.empty()) {
            int x = pq.top().second.first;
            int y = pq.top().second.second;

            int time = pq.top().first;

            pq.pop();

            for(auto dir : directions) {
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                if(x_ >= 0 && x_ < n && y_ >= 0 && y_ < n) {
                    int t = grid[x_][y_];

                    int value = (time >= t ? 0 : t - time);

                    if((time + value) < dist[x_][y_]) {
                        dist[x_][y_] = time + value;
                        pq.push({time + value , {x_ , y_}});
                    }
                }
            }
        }
        return dist[n-1][n-1];
    }
}; 