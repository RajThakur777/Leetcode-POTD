class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();

        vector<int> diff(n+1 , 0);
        for(int i=0; i<shifts.size(); i++){
            int st = shifts[i][0];
            int ed = shifts[i][1];
            int d = shifts[i][2];

            if(d == 0){
                diff[st]--;
                diff[ed+1]++;
            }
            else if(d == 1){
                diff[st]++;
                diff[ed+1]--;
            }
        }

        for(int i=1; i<diff.size(); i++){
            diff[i] += diff[i-1];
        }

        for(int i=0; i<n; i++){
            int shifts = diff[i] % 26;

            if(shifts < 0){
                shifts += 26;
            }
            s[i] = 'a' + ((s[i] - 'a' + shifts) % 26);
        }
        return s;
    }
};