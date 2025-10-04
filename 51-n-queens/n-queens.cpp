class Solution {
public:
    int N;
    bool is_Safe(int i , int j , vector<string> &temp) {
        int row = i;
        int col = j;

        for(int l=row-1; l>=0; l--) {
            if(temp[l][col] == 'Q') {
                return false;
            }
        }

        for(int l=row-1,r=col-1; l>=0 && r>=0; l--,r--) {
            if(temp[l][r] == 'Q') {
                return false;
            }
        }

        for(int l=row-1,r=col+1; l>=0 && r<temp.size(); l--,r++) {
            if(temp[l][r] == 'Q') {
                return false;
            }
        }
        return true;
    }

    void solve(int row , vector<vector<string>> &ans , vector<string> &temp) {
        if(row == N) {
            ans.push_back(temp);
            return;
        }

        for(int col=0; col<temp.size(); col++) {
            if(is_Safe(row , col , temp)) {
                temp[row][col] = 'Q';
                solve(row+1 , ans , temp);
                temp[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;

        N = n;

        vector<string> temp(n, string(n, '.'));
        
        solve(0 , ans , temp);

        return ans;
    }
};