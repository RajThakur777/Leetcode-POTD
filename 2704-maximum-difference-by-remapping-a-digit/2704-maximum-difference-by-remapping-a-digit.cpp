class Solution {
public:
    int minMaxDifference(int num) {
        string maxi;
        string mini;

        string ans = to_string(num);

        char ch;
        char ch2 = ans[0];

        for(int i=0; i<ans.size(); i++){
            if(ans[i] != '9') {
                ch = ans[i];
                break;
            }
        }

        for(int i=0; i<ans.size(); i++) {
            if(ans[i] == ch) {
                maxi += '9';
            }
            else {
                maxi += ans[i];
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
        return stoi(maxi) - stoi(mini);
    }
};