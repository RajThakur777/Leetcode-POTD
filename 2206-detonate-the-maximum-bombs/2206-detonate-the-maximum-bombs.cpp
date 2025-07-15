class Solution {
public:  
    #define ll long long 

    void dfs(int node , unordered_map<int , vector<int>> &mpp , vector<bool> &visited , int &cnt) {
        visited[node] = true;
        cnt++;

        for(auto &v : mpp[node]) {
            if(!visited[v]) {
                dfs(v , mpp , visited , cnt);
            }
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) { 
        int n = bombs.size();

        unordered_map<int , vector<int>> mpp;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
               if (i == j) continue;

              long long x1 = bombs[i][0];
              long long y1 = bombs[i][1];
              long long r1 = bombs[i][2];

              long long x2 = bombs[j][0];
              long long y2 = bombs[j][1];

              long long dx = x2 - x1;
              long long dy = y2 - y1;
              long long distSquared = dx * dx + dy * dy;

            if (distSquared <= r1 * r1) {
                mpp[i].push_back(j);
            }
        }
    }

        int ans = INT_MIN;

        for(int i=0; i<n; i++) {
            vector<bool> visited(n , false);

            int cnt = 0;
            dfs(i , mpp , visited , cnt);

            ans = max(ans , cnt);
        }
        return ans;
    }
};