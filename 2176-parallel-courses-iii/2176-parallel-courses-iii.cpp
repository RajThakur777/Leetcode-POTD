//Topological Sorting:
class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        int N = relations.size();

        unordered_map<int , vector<int>> mpp;
        for(int i=0; i<N; i++) {
            int u = relations[i][0] - 1;
            int v = relations[i][1] - 1;

            mpp[u].push_back(v);
        }

        vector<int> indegree(n , 0);

        vector<int> res(n , 0);

        for(int i=0; i<N; i++) {
            int u = relations[i][0] - 1;
            int v = relations[i][1] - 1;

            indegree[v]++;
        }

        queue<int> q;
        for(int i=0; i<n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
                res[i] = time[i];
            }
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(auto &it : mpp[node]) {
                res[it] = max(res[it] , res[node] + time[it]);
                indegree[it]--;

                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        return *max_element(res.begin() , res.end());
    }
};