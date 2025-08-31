class Solution {
public:
    bool isRow(vector<vector<char>>& board , int r , char ch) {
        for(int col=0; col<9; col++) {
            if(board[r][col] == ch) return false;
        }
        return true;
    }

    bool isCol(vector<vector<char>>& board , int c , char ch) {
        for(int row=0; row<9; row++) {
            if(board[row][c] == ch) return false;
        }
        return true;
    }

    bool isThree(vector<vector<char>>& board , int r , int c , char ch) {
        int sr = r - (r % 3);
        int sc = c - (c % 3);
        for(int i=sr; i<sr+3; i++) {
            for(int j=sc; j<sc+3; j++) {
                if(board[i][j] == ch) return false;
            }
        }
        return true;
    }

    bool isValid(vector<vector<char>>& board , int r , int c , char ch) {
        return (isRow(board , r , ch) && isCol(board , c , ch) && isThree(board , r , c , ch));
    }

    bool solve(vector<vector<char>>& board) {
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if(board[i][j] == '.') {
                    for(char d='1'; d<='9'; d++) {
                        if(isValid(board , i , j , d)) {
                            board[i][j] = d;
                            if(solve(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
