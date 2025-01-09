class Solution {
public:

    bool isPrefix(string str1 , string str2){
        int i = 0;
        int j = 0;

        while(i < str1.size()){
            if(str1[i] != str2[j]){
                return false;
            }
            else {
                i++;
                j++;
            }
        }
        return true;
    }

    int countPrefixes(vector<string>& words, string s) {
        int cnt = 0;
        int n = words.size();

        for(int i=0; i<n; i++){
            string temp = words[i];

            if(isPrefix(temp , s)){
                cnt++;
            }
        }
        return cnt;
    }
};