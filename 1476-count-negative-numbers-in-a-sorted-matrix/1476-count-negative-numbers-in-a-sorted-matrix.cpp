// class Solution {
// public:
//     int countNegatives(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();

//         int cnt = 0;

//         for(int i=0; i<m; i++){
//             for(int j=0; j<n; j++){
//                 if(grid[i][j] < 0){
//                     cnt++;
//                 }
//             }
//         }
//         return cnt;
//     }
// };





class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int cnt = 0;

        for(int i=0; i<m; i++){
            int temp = n;
            int low = 0;
            int high = n-1;

            while(low <= high){
                int mid = (low + high) / 2;

                if(grid[i][mid] < 0){
                    temp = mid;
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            cnt += (n - temp);
        }
        return cnt;
    }
};