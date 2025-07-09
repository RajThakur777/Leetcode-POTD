//Dijktra's Algorithm:
class Solution {
public:

    typedef pair<int , pair<int , int>> P;

    vector<vector<int>> directions = {{-1 , 0} , {0 , -1} , {0 , 1} , {1 , 0}};

    bool isSafe(int x , int y , vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        return (x >= 0 && x < m && y >= 0 && y < n);
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> res(m , vector<int>(n , INT_MAX));

        priority_queue<P , vector<P> , greater<P>> pq;

        pq.push({0 , {0 , 0}});

        res[0][0] = 0;

        while(!pq.empty()) {
            int d = pq.top().first;
            auto it = pq.top().second;

            int x = it.first;
            int y = it.second;

            pq.pop();

            if(x == m-1 && y == n-1) return d;

            for(auto &dir : directions) {
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                if(isSafe(x_ , y_ , heights)) {
                    int dist = max(d , abs((heights[x_][y_] - heights[x][y])));

                    if(((dist < res[x_][y_]))) {
                        res[x_][y_] = dist;
                        pq.push({dist , {x_ , y_}});
                    }
                }
            }
        }
        return res[m-1][n-1];
    }
};