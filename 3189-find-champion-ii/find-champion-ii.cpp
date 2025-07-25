class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        int N = edges.size();

        vector<int> indegree(n , 0);

        for(int i=0; i<N; i++) {
            int v = edges[i][1];

            indegree[v]++;
        }

        int cnt = 0;
        int ans = 0;
        for(int i=0; i<n; i++) {
            if(indegree[i] == 0) {
                cnt++;
                ans = i;
            }
        }
        return (cnt > 1 ? -1 : ans);
    }
};