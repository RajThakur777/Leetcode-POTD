class Solution {
public:

    void dfs(int node , vector<vector<int>> &adj , vector<bool> &vis){
        vis[node] = true;

        for(auto neigh : adj[node]){
            if(!vis[neigh]){
                dfs(neigh , adj , vis);
            }
        }
    }

    bool isInterset(vector<int> &a , vector<int> &b , int k){
        unordered_set<int> st(a.begin() , a.end());
        int count = 0;
        for(int num : b){
            if(st.erase(num)){
                count++;
            }
        }
        return count >= k;
    }

    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n = properties.size();
        int m = properties[0].size();

        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(isInterset(properties[i] , properties[j] , k)){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> vis(n+1 , false);

        int cnt = 0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(i , adj , vis);
                cnt++;
            }
        }
        return cnt;
    }
};