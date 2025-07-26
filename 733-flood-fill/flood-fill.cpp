//DFS:
class Solution {
public:
    int m;
    int n;

    void dfs(int i , int j , int color , vector<vector<int>>& image , int originalColor ,  vector<vector<bool>> &visited) {
        if(i < 0 || i >= m || j < 0 || j >= n || image[i][j] != originalColor || visited[i][j] == true) return;

        image[i][j] = color;
        visited[i][j] = true;

        dfs(i+1 , j , color , image , originalColor , visited);
        dfs(i-1 , j , color , image , originalColor , visited);
        dfs(i , j+1 , color , image , originalColor , visited);
        dfs(i , j-1 , color , image , originalColor , visited);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m = image.size();
        n = image[0].size();

        vector<vector<bool>> visited(m , vector<bool>(n , false));

        dfs(sr , sc , color , image , image[sr][sc] , visited);

        return image;
    }
};