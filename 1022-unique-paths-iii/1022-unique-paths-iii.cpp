// //Code-1:
// class Solution {
// public:
//     int m;
//     int n;

//     int dfs(int i , int j , int count , vector<vector<int>> &grid) {
//         if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == -1) return 0;

//         if(grid[i][j] == 2) {
//             return (count == 0 ? 1 : 0);
//         }

//         int temp = grid[i][j];
//         grid[i][j] = -1;
//         count--;

//         int paths = 0;
//         paths += dfs(i-1 , j , count , grid);
//         paths += dfs(i+1 , j , count , grid);
//         paths += dfs(i , j-1 , count , grid);
//         paths += dfs(i , j+1 , count , grid);

//         grid[i][j] = temp;
//         count++;

//         return paths;
//     }

//     int uniquePathsIII(vector<vector<int>>& grid) {
//         m = grid.size();
//         n = grid[0].size();

//         int start_x = 0;
//         int start_y = 0;

//         int empty = 0;

//         for(int i=0; i<m; i++) {
//             for(int j=0; j<n; j++) {
//                 if(grid[i][j] == 1) {
//                     start_x = i;
//                     start_y = j;
//                 }
//                 else if(grid[i][j] == 0) {
//                     empty++;
//                 }
//             }
//         }

//         return dfs(start_x , start_y , empty+1 , grid);
//     }
// };





//Code-2:
class Solution {
public:
    int m;
    int n;

    void dfs(int i , int j , int count , vector<vector<int>> &grid , int &res) {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == -1) return;

        if(grid[i][j] == 2) {
            if(count == 0) {
                res++;
            }
            return;
        }

        int temp = grid[i][j];
        grid[i][j] = -1;
        count--;

        dfs(i-1 , j , count , grid , res);
        dfs(i+1 , j , count , grid , res);
        dfs(i , j-1 , count , grid , res);
        dfs(i , j+1 , count , grid , res);

        grid[i][j] = temp;
        count++;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int start_x = 0;
        int start_y = 0;

        int empty = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    start_x = i;
                    start_y = j;
                }
                else if(grid[i][j] == 0) {
                    empty++;
                }
            }
        }

        int res = 0;

        dfs(start_x , start_y , empty+1 , grid , res);

        return res;
    }
};