//Dijkstra's Algo:
class Solution {
public:
    
    typedef pair<int , pair<int , int>> P;

    vector<vector<int>> directions = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}};

    bool is_Safe(int x , int y , vector<vector<int>> &moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();

        return (x >= 0 && x < n && y >= 0 && y < m);
    }

    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();

        vector<vector<int>> dist(n , vector<int>(m , INT_MAX));

        priority_queue<P , vector<P> , greater<P>> pq;
        pq.push({0 , {0 , 0}});

        dist[0][0] = 0;

        while(!pq.empty()) {
            int time = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;

            pq.pop();

            if(x == n-1 && y == m-1) return time;

            for(auto &dir : directions) {
                int new_x = x + dir[0];
                int new_y = y + dir[1];

                if(is_Safe(new_x  , new_y , moveTime)) {
                    int moveCost = (new_x + new_y) % 2 == 0 ? 2 : 1;
                    int wait = max((moveTime[new_x][new_y] - time), 0);
                    int new_time = wait + moveCost;

                    if(time + new_time < dist[new_x][new_y]) {
                        dist[new_x][new_y] = time + new_time;
                        pq.push({time + new_time , {new_x , new_y}});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};