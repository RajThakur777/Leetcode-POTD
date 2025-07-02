//DFS:
class Solution {
public:

    void dfs(unordered_map<int , vector<int>> &mpp , int node , vector<bool> &visited) {
        visited[node] = true;

        for(int &v : mpp[node]) {
            if(!visited[v]) {
                dfs(mpp , v , visited);
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        vector<bool> visited(n , false);

        unordered_map<int , vector<int>> mpp;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(stones[j][0] == stones[i][0] || stones[j][1] == stones[i][1]) {
                    mpp[i].push_back(j);
                    mpp[j].push_back(i);
                }
            }
        }

        int cnt = 0;

        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                dfs(mpp , i , visited);
                cnt++;
            }
        }
        return n - cnt;
    }
};