class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent) 
            return false;

        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
        return true;
    }

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        parent.resize(n);
        rank.resize(n, 0);
        vector<int> hasParent(n, 0);

        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }

        for (int i = 0; i < n; ++i) {
            for (int child : {leftChild[i], rightChild[i]}) {
                if (child == -1) continue;

                if (hasParent[child]++) return false;

                if (!Union(i, child)) return false;
            }
        }

        int rootCount = 0;
        for (int i = 0; i < n; ++i) {
            if (hasParent[i] == 0) rootCount++;
        }

        return rootCount == 1;
    }
};
