class Solution {
public:

    void dfs(unordered_map<int , vector<int>> &mpp , int node , vector<bool> &visited , int &cnt) {
        visited[node] = true;
        cnt++;

        for(int &v : mpp[node]) {
            if(!visited[v]) {
                dfs(mpp , v , visited , cnt);
            }
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        int N = edges.size();

        unordered_map<int , vector<int>> mpp;
        for(int i=0; i<N; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            mpp[u].push_back(v);
            mpp[v].push_back(u);
        }

        vector<bool> visited(n , false);

        unordered_map<int, int> mpp2;

        int idx = 0;

        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                int cnt = 0;
                dfs(mpp , i , visited , cnt);

                mpp2[idx] = cnt;
                idx++;
            }
        }

        long long ans = 0;

        vector<long long> res;
        for(auto it : mpp2) {
            res.push_back(it.second);
        }

        sort(res.begin() , res.end());

        vector<long long> prefix(n);
        prefix[0] = res[0];

        for(int i=1; i<res.size(); i++) {
            prefix[i] = prefix[i-1] + res[i];
        }

        for(int i=0; i<res.size(); i++) {
            ans += (long long)((res[i]) * (prefix[res.size() - 1] - res[i]));
        }
        return (ans / 2);
    }
};