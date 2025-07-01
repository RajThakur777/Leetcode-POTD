class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int , vector<int>> mpp;

        int n = prerequisites.size();

        for(int i=0; i<n; i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            mpp[v].push_back(u);
        }

        vector<int> res;

        vector<int> indegree(numCourses);
        for(int i=0; i<n; i++) {
            indegree[prerequisites[i][0]]++;
        }


        queue<int> q;
        for(int i=0; i<numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            res.push_back(curr);

            for(int &v : mpp[curr]) {
                indegree[v]--;

                if(indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        return (res.size() == numCourses);
    }
};