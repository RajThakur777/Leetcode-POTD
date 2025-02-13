class Solution {
public:

    bool check(vector<vector<char>>& board , int r , int c , char ch){
        //checking for present row:
        for(int i=0; i<9; i++){
            if(board[r][i] == ch) return false;
        }

        //checking for present column:
        for(int i=0; i<9; i++){
            if(board[i][c] == ch) return false;
        }

        //checking for 3*3 grid:
        int r1 = r - r % 3;
        int c1 = c - c % 3;

        for(int i=r1; i<r1+3; i++){
            for(int j=c1; j<c1+3; j++){
                if(board[i][j] == ch) return false;
            }
        }
        return true;
    }

    bool helper(vector<vector<char>>& board , int r , int c){
        if(r == 9) return true;

        if(c == 9) return helper(board , r+1 , 0);

        //not a empty cell:
        if(board[r][c] != '.'){
            return helper(board , r , c+1);
        }

        //empty cell:
        for(char ch='1'; ch<='9'; ch++){
            if(check(board , r , c , ch) == false) continue;
            board[r][c] = ch;
            bool ans = helper(board , r , c+1);
            if(ans == true){
                return true;
            }
            board[r][c] = '.';
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        bool ans = helper(board , 0 , 0);
    }
};