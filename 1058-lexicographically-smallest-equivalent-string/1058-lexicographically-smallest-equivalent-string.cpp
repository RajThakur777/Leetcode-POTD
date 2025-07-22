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

        parent[max(x_parent , y_parent)] = min(x_parent , y_parent);
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();

        parent.resize(26);
        rank.resize(26 , 0);

        for(int i=0; i<26; i++) {
            parent[i] = i;
        }

        for(int i=0; i<n; i++) {
            int parent_s1 = s1[i] - 'a';
            int parent_s2 = s2[i] - 'a';

            if(parent_s1 != parent_s2) {
                Union(parent_s1 , parent_s2);
            }
        }

        string ans;

        for(int i=0; i<baseStr.size(); i++) {
            int parent = find(baseStr[i] - 'a');

            char ch = parent + 'a';

            ans += ch;
        }
        return ans;
    }
};