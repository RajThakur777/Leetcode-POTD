class Solution {
public:
    unordered_map<int , vector<int>> adj;
    unordered_map<int , int> bobMap;
    int ans;

    bool DFSBob(int curr , int t , vector<bool> &visited){
        visited[curr] = true;
        bobMap[curr] = t;

        if(curr == 0){
            return true;
        }

        for(auto &neighbour : adj[curr]){
            if(!visited[neighbour]){
                if(DFSBob(neighbour , t+1 , visited) == true){
                    return true;
                }
            }
        }
        bobMap.erase(curr);
        return false;
    }

    void DFSAlice(int curr , int t , int income , vector<bool> &visited , vector<int> &amount){
        visited[curr] = true;
        
        if(bobMap.find(curr) == bobMap.end() || t < bobMap[curr]){
            income += amount[curr];
        }
        else if(t == bobMap[curr]){
            income += (amount[curr] / 2);
        }

        if(adj[curr].size() == 1 && curr != 0){
            ans = max(ans , income);
        }

        for(auto &neighbour : adj[curr]){
            if(!visited[neighbour]){
                DFSAlice(neighbour , t+1 , income , visited , amount);
            }
        }
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();

        ans = INT_MIN;

        for(vector<int> &edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        //Finding time for bob to reach each node:
        int time = 0;
        vector<bool> visited(n , false);
        DFSBob(bob , time , visited);

        int income = 0;
        visited.assign(n , false);
        DFSAlice(0 , 0 , income , visited , amount);

        return ans;
    }
};