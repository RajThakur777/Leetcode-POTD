//DFS:
class Solution {
public:

    vector<int> dfs(unordered_map<int , vector<int>> &mpp , int node , int parent , vector<int> &res , string &labels) {
        vector<int> my_cnt(26 , 0);

        char ch = labels[node];

        my_cnt[ch - 'a'] = 1;

        for(auto &it : mpp[node]) {
            if(it == parent) continue;

            vector<int> child_count(26 , 0);
            child_count = dfs(mpp , it , node , res , labels);

            for(int j=0; j<26; j++) {
                my_cnt[j] += child_count[j];
            }
        }
        res[node] = my_cnt[ch - 'a'];

        return my_cnt;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        int N = edges.size();

        unordered_map<int , vector<int>> mpp;
        for(int i=0; i<N; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            mpp[u].push_back(v);
            mpp[v].push_back(u);
        }

        vector<int> res(n , 0);

        dfs(mpp , 0 , -1 , res , labels);

        return res;
    }
};