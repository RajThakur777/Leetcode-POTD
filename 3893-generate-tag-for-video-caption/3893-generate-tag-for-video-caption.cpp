class Solution {
public:
    string generateTag(string caption) {
        string ans;

        ans += '#';

        caption[0] = tolower(caption[0]);

        for(int i=0; i<caption.size(); i++) {
            int j = i;

            while(j < caption.size() && caption[j] != ' ') {
                j++;
            }

            for(int k=i; k<j; k++) {
                caption[k] = tolower(caption[k]);
            }
            i = j;
        }

        for(int i=0; i<caption.size()-1; i++) {
            if(caption[i] == ' ') {
                caption[i+1] = toupper(caption[i+1]);
            }
        }


        string res;
        for(int i=0; i<caption.size(); i++) {
            if(caption[i] == ' ') {
                continue;
            }

            res += caption[i];
        }

        int val = 0;
        if(res.size() > 99) {
            val = 99;
        }
        else {
            val = res.size();
        }

        for(int i=0; i<val; i++) {
            ans += res[i];
        }

        ans[1] = tolower(ans[1]);
        return ans;
    }
};