//DSU:
class Solution {
public:

    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if(x == parent[x]) return x;

        return parent[x] = find(parent[x]);
    }

    void Union(int x , int y) {
        int parent_x = find(x);
        int parent_y = find(y);

        if(parent_x == parent_y) return;

        if(rank[parent_x] > rank[parent_y]) {
            parent[parent_y] = parent_x; 
        }
        else if(rank[parent_y] > rank[parent_x]) {
            parent[parent_x] = parent_y;
        }
        else {
            parent[parent_y] = parent_x;
            rank[parent_x]++;
        }
    }

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        parent.resize(n);
        rank.resize(n , 0);

        for(int i=0; i<n; i++) {
            parent[i] = i;
        }

        int i = 0;
        int j = 1;

        while(i < n && j < n) {
            while(j < n) {
                if(nums[j] - nums[i] > maxDiff) {
                    i++;
                }
                else {
                    Union(i , j);
                    j++;
                }
            }
        }

        vector<bool> ans;

        for(int i=0; i<queries.size(); i++) {
            int u = queries[i][0];
            int v = queries[i][1];

            if(find(u) == find(v)) {
                ans.push_back(true);
            }
            else {
                ans.push_back(false);
            }
        }
        return ans;
    }
};