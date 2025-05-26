class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        unordered_map<int , vector<int>> adj;

        int N = colors.size();

        vector<int> indegree(N , 0);

        for(auto &vec : edges){
            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        vector<vector<int>> t(N , vector<int>(26 , 0));

        for(int i=0; i<N; i++){
            if(indegree[i] == 0){
                q.push(i);
                t[i][colors[i] - 'a'] = 1;
            }
        }

        int ans = 0;

        int cntNodes = 0;

        while(!q.empty()){
            int u = q.front();

            q.pop();

            cntNodes++;

            ans = max(ans , t[u][colors[u] - 'a']);

            for(int &v : adj[u]){
                for(int c=0; c<26; c++){
                    t[v][c] = max(t[v][c] , t[u][c] + (colors[v] - 'a' == c));
                }

                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }
        if(cntNodes < N) return -1;

        return ans;
    }
};