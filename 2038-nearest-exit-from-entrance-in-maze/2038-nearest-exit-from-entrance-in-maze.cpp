//Standard BFS Algo:
class Solution {
public:

    vector<vector<int>> directions = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}};

    bool is_Safe(int x , int y , vector<vector<char>>& maze) {
        int m = maze.size();
        int n = maze[0].size();

        return (x >= 0 && x < m && y >= 0 && y < n);
    }

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();

        queue<pair<int , int>> q;
        q.push({entrance[0] , entrance[1]});

        maze[entrance[0]][entrance[1]] = '+';

        int cnt = 0;

        while(!q.empty()) {
            int sz = q.size();

            while(sz--) {
                pair<int , int> temp = q.front();
                q.pop();

                int x = temp.first;
                int y = temp.second;

                if(temp != make_pair(entrance[0], entrance[1]) && 
                   (temp.first == 0 || temp.first == m-1 || temp.second == 0 || temp.second == n-1))
                    return cnt;

                for(auto &dir : directions) {
                    int x_ = x + dir[0];
                    int y_ = y + dir[1];

                    if(is_Safe(x_ , y_ , maze) && maze[x_][y_] != '+') {
                        q.push({x_ , y_});
                        maze[x_][y_] = '+';
                    }
                }
            }
            cnt++;
        }
        return -1;
    }
};