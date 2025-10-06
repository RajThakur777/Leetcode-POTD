//We will use Dijiktra's Algorithm:
class Solution {
public:
    typedef pair<int , pair<int , int>> P;

    vector<vector<int>> directions = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}};

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        priority_queue<P , vector<P> , greater<P>> pq;
        pq.push({grid[0][0] , {0 , 0}});

        vector<vector<int>> ans(n , vector<int>(n , INT_MAX));

        ans[0][0] = 0;

        while(!pq.empty()) {
            int t = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;

            pq.pop();

            for(auto dir : directions) {
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                if(x_ >= 0 && x_ < n && y_ >= 0 && y_ < n) {
                    int v = grid[x_][y_];

                    int time = t + (v <= t ? 0 : v - t);

                    if(time < ans[x_][y_]) {    
                        ans[x_][y_] = time;
                        pq.push({time , {x_ , y_}});
                    }
                }
            }
        }
        return ans[n-1][n-1];
    }
};