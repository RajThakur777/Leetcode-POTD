//DFS:
class Solution {
public:

    void dfs(int node , vector<bool> &visited , vector<vector<int>> &rooms) {
        visited[node] = true;

        for(auto it : rooms[node]) {
            if(!visited[it]) {
                dfs(it , visited , rooms);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int N = rooms.size();

        vector<bool> visited(N , false);

        dfs(0 , visited , rooms);

        for(int i=0; i<N; i++) {
            if(!visited[i]) {
                return false;
            }
        }
        return true;
    }
};