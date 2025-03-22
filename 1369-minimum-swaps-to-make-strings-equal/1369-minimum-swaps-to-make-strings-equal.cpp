class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int cnt_x  = 0;
        int cnt_y = 0;

        int n = s1.size();

        for(int i=0; i<s1.size(); i++){
            if(s1[i] == 'x'){
                cnt_x++;
            }
            else {
                cnt_y++;
            }
        }

        for(int i=0; i<s2.size(); i++){
            if(s2[i] == 'x'){
                cnt_x++;
            }
            else {
                cnt_y++;
            }
        }

        if(cnt_x % 2 != 0 || cnt_y % 2 != 0) return -1;

        int x = 0;
        int y = 0;

        for(int i=0; i<n; i++) {
            if(s1[i] != s2[i]){
                if(s1[i] == 'x'){
                    x++;
                }
                else {
                    y++;
                }
            }
            else {
                continue;
            }
        }
        return (x + 1) / 2 + (y + 1) / 2;
    }
};