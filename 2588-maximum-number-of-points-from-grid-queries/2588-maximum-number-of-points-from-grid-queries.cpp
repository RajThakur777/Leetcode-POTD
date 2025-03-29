// //Brute force : BFS
// class Solution {
// public:
//     int dx[4] = {-1 , 0 , 1 , 0};
//     int dy[4] = {0 , 1 , 0 , -1};

//     int bfs(vector<vector<int>> &grid , int m , int n , int val){
//         vector<vector<bool>> visited(m , vector<bool>(n , false));

//         queue<pair<int , int>> q;
//         int points = 0;
//         q.push({0 , 0});

//         visited[0][0] = true;

//         while(!q.empty()){
//             pair<int , int> p = q.front();

//             int x = p.first;
//             int y = p.second;

//             q.pop();

//             if(grid[x][y] > val) continue;

//             points++;

//             for(int i=0; i<4; i++){
//                 int nrow = x + dx[i];
//                 int ncol = y + dy[i];

//                 if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !visited[nrow][ncol] && grid[nrow][ncol] < val){
//                     visited[nrow][ncol] = true;
//                     q.push({nrow , ncol});
//                 }
//             }
//         }
//         return points;
//     }

//     vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
//         int m = grid.size();
//         int n = grid[0].size();

//         int q = queries.size();
//         vector<int> res(q , 0);

//         for(int i=0; i<q; i++){
//             res[i] = bfs(grid , m , n , queries[i]);
//         }
//         return res;
//     }
// };









class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size();
        int n = grid[0].size();

        int Q = queries.size();
        vector<int> result(Q, 0);

        vector<pair<int, int>> sortedQ;
        for(int i = 0; i < Q; i++) {
            sortedQ.push_back({queries[i], i});
        }

        sort(begin(sortedQ), end(sortedQ));

        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int points = 0;
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;


        for(int i = 0; i < Q; i++) {
            int queryValue = sortedQ[i].first;
            int idx        = sortedQ[i].second;
            while(!pq.empty() && pq.top()[0] < queryValue) {
                int i = pq.top()[1];
                int j = pq.top()[2];
                pq.pop();
                points++;

                for(auto &dir : directions) {
                    int i_ = i + dir[0];
                    int j_ = j + dir[1];
                    if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && !visited[i_][j_]) {
                        pq.push({grid[i_][j_], i_, j_});
                        visited[i_][j_] = true;
                    }
                }
            }
            result[idx] = points;
        }
        
        return result;
    }
};