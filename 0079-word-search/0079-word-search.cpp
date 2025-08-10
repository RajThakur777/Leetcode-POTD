class Solution {
public:
    int m;
    int n;

    bool dfs(int i , int j , vector<vector<char>> &board , string word , int idx) {
        if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[idx] || board[i][j] == '.') return false;

        if(idx == word.size() - 1) return true;

        char ch = board[i][j];

        board[i][j] = '.';

        bool f1 = dfs(i-1 , j , board , word , idx + 1);
        bool f2 = dfs(i+1 , j , board , word , idx + 1);
        bool f3 = dfs(i , j-1 , board , word , idx + 1);
        bool f4 = dfs(i , j+1 , board , word , idx + 1);

        board[i][j] = ch;

        return (f1 || f2 || f3 || f4);
    }

    bool exist(vector<vector<char>>& board, string word) {  
        m = board.size();
        n = board[0].size();

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j] == word[0]) {
                    if(dfs(i , j , board , word , 0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};