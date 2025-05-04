class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int m = bank.size();

        int ans = 0;
        int prev = 0;
        for(int i=0; i<m; i++){
            string s = bank[i];
            int cnt = 0;

            for(int j=0; j<s.size(); j++){
                if(s[j] == '1'){
                    cnt++;
                }
            }
            if(cnt > 0){
                ans += (prev * cnt);
                prev = cnt;
            }
        }
        return ans;
    }
};