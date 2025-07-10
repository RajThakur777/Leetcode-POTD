class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) { 
        int n =  prerequisites.size();

        unordered_map<int , vector<int>> mpp;
        for(int i=0; i<n; i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            mpp[u].push_back(v);
        }

        vector<int> indegree(numCourses , 0);

        for(int i=0; i<numCourses; i++) {
            for(int &v : mpp[i]) {
                indegree[v]++;
            }
        }

        queue<int> q;
        for(int i=0; i<numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        unordered_map<int , unordered_set<int>> res;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(int &v : mpp[node]) {
                res[v].insert(node);

                for(auto &it : res[node]) {
                    res[v].insert(it);
                }

                indegree[v]--;

                if(indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        vector<bool> answer;
        for (auto q : queries) {
            answer.push_back(res[q[1]].contains(q[0]));
        }

        return answer;
    }
};