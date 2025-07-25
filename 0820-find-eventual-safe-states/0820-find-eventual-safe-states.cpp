//Topological Sorting Concept:
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;

        int n = graph.size();

        vector<vector<int>> adj(n);

        vector<int> indegree(n);

        for(int i=0; i<n; i++) {
            for(auto &v : graph[i]) {
                adj[v].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        for(int i=0; i<n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for(auto &it : adj[node]) {
                indegree[it]--;

                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        sort(ans.begin() , ans.end());

        return ans;
    }
};