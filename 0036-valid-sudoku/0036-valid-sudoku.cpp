class Solution {
public:
    bool isValid(int sr , int er , int sc , int ec , vector<vector<char>>& board) {
        set<char> st;
        for(int i=sr; i<=er; i++) {
            for(int j=sc; j<=ec; j++) {
                if(board[i][j] == '.') continue;
                if(st.find(board[i][j]) != st.end()) {
                    return false;
                }
                st.insert(board[i][j]);
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {  
        int m = board.size();
        int n = board[0].size();

        for(int i=0; i<m; i++) {
            set<char> st;
            for(int j=0; j<n; j++) {
                if(board[i][j] == '.') continue;
                if(st.find(board[i][j]) != st.end()) {
                    return false;
                }
                st.insert(board[i][j]);
            }
        }

        for(int j=0; j<n; j++) {
            set<char> st;
            for(int i=0; i<m; i++) {
                if(board[i][j] == '.') continue;
                if(st.find(board[i][j]) != st.end()) {
                    return false;
                }
                st.insert(board[i][j]);
            }
        }

        for(int sr=0; sr<m; sr+=3) {
            for(int sc=0; sc<n; sc+=3) {
                if(!isValid(sr, sr+2, sc, sc+2, board)){
                    return false;
                } 
            }
        }

        return true;
    }
};
