class Solution {
public:
    int maxDiff(int num) {
        string ans = to_string(num);

        char ch1;
        for(int i=0; i<ans.size(); i++) {
            if(ans[i] != '9') {
                ch1 = ans[i];
                break;
            }
        }

        string maxi;
        for(int i=0; i<ans.size(); i++) {
            if(ans[i] == ch1) {
                maxi += '9';
            }
            else {
                maxi += ans[i];
            }
        }

        string mini;
        if(ans[0] != '1') {
            char ch = ans[0];

            for(int i=0; i<ans.size(); i++) {
                if(ans[i] == ch) {
                    mini += '1';
                }
                else {
                    mini += ans[i];
                }
            }
        }
        else if(ans[0] == '1'){
            char ch2;
            for(int i=0; i<ans.size(); i++) {
                if(ans[i] != '1' && ans[i] != '0') {
                    ch2 = ans[i];
                    break;
                }
            }

            for(int i=0; i<ans.size(); i++) {
                if(ans[i] == ch2) {
                    mini += '0';
                }
                else {
                    mini += ans[i];
                }
            }
        }
        return stoi(maxi) - stoi(mini);
    }
};