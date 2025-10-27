class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int m = bank.size();
        int n = bank[0].size();

        vector<int> row(m);

        for(int i=0; i<m; i++) {
            int cnt = 0;
            for(int j=0; j<n; j++) {
                if(bank[i][j] == '1') {
                    cnt++;
                }
            }
            row[i] = cnt;
        }

        vector<int> res;
        for(int i=0; i<m; i++) {
            if(row[i] > 0) {
                res.push_back(row[i]);
            }
        }

        if(res.empty()) return 0;

        int ans = 0;
        for(int i=0; i<res.size()-1; i++) {
            ans += ((res[i] * res[i+1]));
        }
        return ans;
    }
};