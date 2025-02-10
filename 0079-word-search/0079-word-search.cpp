class Solution {
public:
    int dx[4] = {-1 , 0 , 1 , 0};
    int dy[4] = {0 , 1 , 0 , -1};

    bool helper(int r , int c , vector<vector<char>>& board , string word) {
        if(word.size() == 0) return true;

        int m = board.size();
        int n = board[0].size();
    
        if(r < 0 || r >= m || c < 0 || c >= n || board[r][c] != word[0]) return false;

        char ch = board[r][c];
        board[r][c] = '*';
        string str = word.substr(1);

        bool ans = 0;

        for(int i=0; i<4; i++){
            int nr = r + dx[i];
            int nc = c + dy[i];

            ans |= helper(nr , nc , board , str);
        }
        board[r][c] = ch;

        return ans;
    }

    bool exist(vector<vector<char>>& board, string word) { 
        int m = board.size();
        int n = board[0].size();

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == word[0]){
                    bool ans = helper(i , j , board , word);

                    if(ans == true){
                        return true;
                    }
                }
            }
        } 
        return false;
    }
};