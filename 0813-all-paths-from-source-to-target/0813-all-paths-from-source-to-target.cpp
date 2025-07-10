class Solution {
public:

    void dfs(vector<vector<int>>& graph , int src , int dest , vector<int> &path , vector<vector<int>> &ans) {
        path.push_back(src);

        if(src == dest) {
            ans.push_back(path);
            return;
        }

        for(int &v : graph[src]) {
            dfs(graph , v , dest , path , ans);
            path.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;

        int n = graph.size();

        int src = 0;
        int dest = n - 1;

        vector<int> path;

        dfs(graph , src , dest , path , ans);

        return ans;
    }
};