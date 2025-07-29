class Solution {
public:
    int m;
    int n;

    void dfs1(int i , int j , vector<vector<char>> &board) {
        if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O') return;

        board[i][j] = '#';

        dfs1(i+1 , j , board);
        dfs1(i-1 , j , board);
        dfs1(i , j+1 , board);
        dfs1(i , j-1 , board);
    }

       void dfs2(int i , int j , vector<vector<char>> &board) {
        if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] == 'X' || board[i][j] == '#') return;

        board[i][j] = 'X';

        dfs2(i+1 , j , board);
        dfs2(i-1 , j , board);
        dfs2(i , j+1 , board);
        dfs2(i , j-1 , board);
    }

    void solve(vector<vector<char>>& board) {  
        m = board.size();
        n = board[0].size();

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if((i == 0 || i == m-1 || j == 0 || j == n-1) && board[i][j] == 'O') {
                    dfs1(i , j , board);
                }
            }
        }

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j] == 'O') {
                    dfs2(i , j , board);
                }
            }
        }

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};