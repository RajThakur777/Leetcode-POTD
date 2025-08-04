class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int n = queries.size();

        vector<string> ans;

        for(int i=0; i<n; i++) {
            string str1 = queries[i];

            for(int j=0; j<dictionary.size(); j++) {
                string str2 = dictionary[j];
                int cnt = 0;

                for(int k=0; k<str1.size(); k++) {
                    if(str1[k] != str2[k]) {
                        cnt++;
                    }
                }

                if(cnt <= 2) {
                    ans.push_back(str1);
                    break;
                }
            }
        }
        return ans;
    }
};