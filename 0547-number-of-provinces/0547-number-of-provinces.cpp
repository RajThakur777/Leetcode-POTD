class Solution {
public:

    void dfs(int node , unordered_map<int , vector<int>> &mpp , vector<bool> &visited) {
        visited[node] = true;

        for(int &v : mpp[node]) {
            if(!visited[v]) {
                dfs(v , mpp , visited);
            } 
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<bool> visited(n , false);

        int ans = 0;

        unordered_map<int , vector<int>> mpp;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(isConnected[i][j] == 1) {
                    mpp[i].push_back(j);
                    mpp[j].push_back(i);
                }
            }
        }

        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                dfs(i , mpp , visited);
                ans++;
            }
        }
        return ans;
    }
};