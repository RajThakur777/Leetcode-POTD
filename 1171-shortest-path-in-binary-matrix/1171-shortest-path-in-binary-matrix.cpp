// //BFS:
// class Solution {
// public:

//     vector<vector<int>> directions = {{1 , 1} , {0 , 1} , {1 , 0} , {-1 , 0} , {0 , -1} , {-1 , -1} , {1 , -1} , {-1 , 1}};


//     bool isSafe(int x , int y , vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();

//         return (x >= 0 && x < m && y >= 0 && y < n);
//     }

//     int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();

//         if(m == 0 || n == 0 || grid[0][0] != 0) return -1;

//         queue<pair<int , int>> q;
//         q.push({0 , 0});
//         grid[0][0] = 1;

//         int cnt = 0;

//         while(!q.empty()) {
//             int N = q.size();

//             while(N--) {
//                 auto it = q.front();
//                 q.pop();

//                 int x_ = it.first;
//                 int y_ = it.second;

//                 if(x_ == m-1 && y_ == n-1) return cnt + 1;

//                 for(auto &dir : directions) {
//                     int x = x_ + dir[0];
//                     int y = y_ + dir[1];

//                     if(isSafe(x , y , grid) && grid[x][y] == 0) {
//                         grid[x][y] = 1;
//                         q.push({x , y});
//                     }
//                 }
//             }
//             cnt++;
//         }
//         return -1;
//     }
// };







class Solution {
public:
    typedef pair<int , pair<int , int>> P;

    bool isSafe(int x , int y , vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        return (x >= 0 && x < m && y >= 0 && y < n);
    }

    vector<vector<int>> directions = {{1 , 1} , {0 , 1} , {1 , 0} , {-1 , 0} , {0 , -1} , {-1 , -1} , {1 , -1} , {-1 , 1}};


    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if(m == 0 || n == 0 || grid[0][0] != 0) return -1;

        vector<vector<int>> res(m , vector<int>(n , INT_MAX));

        priority_queue<P , vector<P> , greater<P>> pq;
        pq.push({0 , {0 , 0}});

        res[0][0] = 0;

        while(!pq.empty()) {
            int d = pq.top().first;
            pair<int , int> p = pq.top().second;

            pq.pop();

            int x = p.first;
            int y = p.second;

            for(auto &dir : directions) {
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                int dist = 1;

                if(isSafe(x_ , y_ , grid) && grid[x_][y_] == 0 && d + dist < res[x_][y_]) {
                    res[x_][y_] = d + dist;
                    pq.push({d + dist , {x_ , y_}});
                }
            }
        }
        if(res[m-1][n-1] == INT_MAX) return -1;
        
        return res[m-1][n-1] + 1;
    }
};