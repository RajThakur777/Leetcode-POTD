class Solution {
public:

    vector<vector<int>> directions = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}};

    int m;
    int n;

    int dfs(int i , int j , vector<vector<char>>& board) {
        if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] == '.') return 0;

        int cnt = board[i][j];
        board[i][j] = '.';

        for(auto &dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            cnt += dfs(i_ , j_ , board);
        }
        return cnt;
    }

    int countBattleships(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();

        int ans = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j] == 'X') {
                    ans++;
                    dfs(i , j , board);
                }
            }
        }
        return ans;
    }
};