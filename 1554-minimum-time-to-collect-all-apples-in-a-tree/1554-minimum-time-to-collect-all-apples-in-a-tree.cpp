//DFS:
class Solution {
public:

    int dfs(unordered_map<int , vector<int>> &mpp , int node , int parent ,vector<bool> &hasApple) {
        int time = 0;

        for(auto &it : mpp[node]) {
            if(it == parent) continue;

            int child_time = dfs(mpp , it , node , hasApple);

            if(child_time > 0 || hasApple[it]) {
                time += child_time + 2;
            }
        }
        return time;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {  
        int N = edges.size();

        unordered_map<int , vector<int>> mpp;
        for(int i=0; i<N; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            mpp[u].push_back(v);
            mpp[v].push_back(u);
        }

        return dfs(mpp , 0 , -1 , hasApple);
    }
};