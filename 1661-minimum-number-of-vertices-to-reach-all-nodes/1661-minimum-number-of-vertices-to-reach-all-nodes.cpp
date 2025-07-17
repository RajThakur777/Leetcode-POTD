class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        int N = edges.size();

        vector<int> indegree(n , 0);
        for(int i=0; i<N; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            indegree[v]++;
        }

        vector<int> ans;
        for(int i=0; i<n; i++) {
            if(indegree[i] == 0) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};