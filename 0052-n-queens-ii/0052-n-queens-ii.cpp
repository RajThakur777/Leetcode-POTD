class Solution {
public:

bool check(int r , int c , vector<string> &v , int n){
        //check vertical direction:
        for(int i=r; i>=0; i--){
            if(v[i][c] == 'Q') return false;
        }

        //check left diagonal:
        for(int i=r,j=c; i>=0 && j>=0; i--,j--){
            if(v[i][j] == 'Q') return false;
        }

        //check right diagonal:
        for(int i=r,j=c; i>=0 && j<n; i--,j++){
            if(v[i][j] == 'Q') return false;
        }
        return true;
    }
    
     void helper(int r , int &cnt , vector<string> &v , int n){
        if(r == n){
            cnt++;
            return;
        }

        for(int i=0; i<n; i++){
            if(check(r , i , v , n) == false) continue;

            v[r][i] = 'Q';
            helper(r+1 , cnt , v , n);
            v[r][i] = '.';
        }
    }

    int totalNQueens(int n) {
        int cnt = 0;

        vector<vector<string>> ans;

        string temp(n , '.');

        vector<string> v(n , temp);

        helper(0 , cnt , v , n);

        return cnt;
    }
};