class Solution {
public:
    
    vector<int> parent;
    vector<int> rank;

    int find (int x) {
        if (x == parent[x]) 
            return x;

        return parent[x] = find(parent[x]);
    }

    void Union (int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent) 
            return;

        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if(rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    
    bool isSimilar(string &s1, string &s2) {
        
        int n = s1.length();
        int diff = 0;
        for(int i = 0; i<n; i++) {
            if(s1[i] != s2[i])
                diff++;
        }
        
        
        return diff == 2 || diff == 0;
    }
    
   
    int numSimilarGroups(vector<string>& strs) {
        
        int n = strs.size();
        parent.resize(n);
        rank.resize(n);
        
        for(int i = 0; i<n; i++)
            parent[i] = i;
        
        int groups = n; 
 
        
        for(int i = 0; i<n; i++) {
            for(int j = i+1; j<n; j++) {
                
                if(isSimilar(strs[i], strs[j]) && find(i) != find(j)) {
                    groups--;
                    Union(i, j);
                }
                
            }
        }
        
        return groups;
    }
};