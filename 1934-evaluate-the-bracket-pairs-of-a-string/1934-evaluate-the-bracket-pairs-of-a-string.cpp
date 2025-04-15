class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        map<string , string> mpp;

        for(int i=0; i<knowledge.size(); i++){
            mpp[knowledge[i][0]] = knowledge[i][1];
        }

        string ans = "";

        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                int j = i+1;

                string temp = "";
                while(j < s.size() && s[j] != ')'){
                    temp += s[j];
                    j++;
                }

                if(mpp.find(temp) == mpp.end()){
                    ans += '?';
                }
                else {
                    ans += mpp[temp];
                }
                i += temp.size() + 1;
            }
            else {
                ans += s[i];
            }
        }
        return ans;
    }
};