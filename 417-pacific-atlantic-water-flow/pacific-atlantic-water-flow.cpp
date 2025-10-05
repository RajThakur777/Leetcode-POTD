class Solution {
public:
    int m;
    int n;

    vector<vector<int>> ht;

    vector<vector<int>> directions = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}};

    vector<vector<int>> bfs(queue<pair<int , int>> &q) {
        vector<vector<int>> visited(m , vector<int>(n , 0));

        while(!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;

            q.pop();

            visited[i][j] = 1;

            for(auto dir : directions) {
                int i_ = i + dir[0];
                int j_ = j + dir[1];

                if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n) {
                    if(visited[i_][j_] == 1) continue;

                    if(ht[i_][j_] < ht[i][j]) continue;

                    q.push({i_ , j_});
                }
            }
        }
        return visited;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        ht = heights;

        queue<pair<int , int>> pacific;
        queue<pair<int , int>> atlantic;

        for(int i=0; i<n; i++) {
            pacific.push({0 , i});
        }

        for(int i=0; i<m; i++) {
            pacific.push({i , 0});
        }

        for(int i=0; i<n; i++) {
            atlantic.push({m-1 , i});
        }

        for(int i=0; i<m; i++) {
            atlantic.push({i , n-1});
        }

        vector<vector<int>> v1 = bfs(pacific);

        vector<vector<int>> v2 = bfs(atlantic);

        vector<vector<int>> res;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(v1[i][j] == 1 && v2[i][j] == 1) {
                    res.push_back({i , j});
                }
            }
        }
        return res;
    }
};