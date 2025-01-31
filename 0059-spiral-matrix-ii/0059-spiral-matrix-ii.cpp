class Solution {
public:
    vector<vector<int>> generateMatrix(int n) { 
        vector<vector<int>> res(n , vector<int>(n));

        int sr = 0;
        int sc = 0;
        int er = n-1;
        int ec = n-1;

        int num = 1;

        while(sr <= er && sc <= ec){
            for(int i=sc; i<=ec; i++){
                res[sr][i] = num++;
            }
            sr++;

            for(int i=sr; i<=er; i++){
                res[i][ec] = num++;
            }
            ec--;

            if(sc <= ec){
                for(int i=ec; i>=sc; i--){
                res[er][i] = num++;
                }
            }
            er--;

            if(sr <= er) {
                for(int i=er; i>=sr; i--){
                res[i][sc] = num++;
                }
            }
            sc++;
        }     
        return res;
    }
};