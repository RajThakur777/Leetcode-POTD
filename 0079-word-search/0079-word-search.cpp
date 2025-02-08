//Recursion:
class Solution {
public:
 
    int dx[4] = {0 , 0 , 1 , -1};
    int dy[4] = {1 , -1 , 0 , 0};

    bool helper(vector<vector<char>>& board , int i , int j , string word){
        if(word.size() == 0) return true;

        int n = board.size();
        int m = board[0].size();

        if(i < 0 || i >= n || j < 0 || j >= m || board[i][j] != word[0]) return false;

        char ch = board[i][j];
        board[i][j] = '*';
        
        string s = word.substr(1);

        bool ans = 0;
        for(int k=0; k<4; k++){
            int nr = i + dx[k];
            int nc = j + dy[k];

            ans |= helper(board , nr , nc , s);
        }
        board[i][j] = ch;
    
        return ans;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == word[0]){
                    bool ans = helper(board , i , j , word);

                    if(ans) return true;
                }
            }
        }
        return false;
    }
};