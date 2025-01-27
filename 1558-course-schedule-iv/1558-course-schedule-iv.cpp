//BFS - Topological Sort:
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int N = numCourses;
        vector<int> adj[N];

        for(auto it : prerequisites){
            adj[it[0]].push_back(it[1]);
        }

        int inDegree[N];
        for(int i=0; i<N; i++){
            inDegree[i] = 0;
        }

        for(int i=0; i<N; i++){
            for(auto it : adj[i]){
                inDegree[it]++;
            }
        }

        queue<int> q;
        for(int i=0; i<N; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }

        map<int , set<int>> mpp;
        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(auto v : adj[u]){
                mpp[v].insert(u);
                mpp[v].insert(mpp[u].begin() , mpp[u].end());

                inDegree[v]--;

                if(inDegree[v] == 0){
                    q.push(v);
                }
            }
        }
        vector<bool> ans;
        for(auto it : queries){
            int u = it[0];
            int v = it[1];

            if(mpp[v].find(u) != mpp[v].end()){
                ans.push_back(true);
            }
            else {
                ans.push_back(false);
            }
        }
        return ans;
    }
};