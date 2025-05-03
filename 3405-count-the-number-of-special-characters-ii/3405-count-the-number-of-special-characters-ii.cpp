class Solution {
public:

    bool isLower(char ch){
        return (ch >= 'a' && ch <= 'z');
    }

    bool isUpper(char ch) {
        return (ch >= 'A' && ch <= 'Z');
    }

    int numberOfSpecialChars(string word) {
        int n = word.size();

        map<char , int> mpp1;
        for(int i=0; i<n; i++){
            if(isLower(word[i])){
               mpp1[word[i]] = i;
            }
        }

        map<char , int> mpp2;
        for(int i=0; i<n; i++) {
            char ch = word[i];

            if(isUpper(ch) && mpp2.find(ch) == mpp2.end()){
                mpp2[ch] = i;
            }
        }

        int cnt = 0;
        for(auto it : mpp1){
            char ch = it.first;
            int idx = it.second;

            if(mpp2.find(toupper(ch)) != mpp2.end() && idx < mpp2[toupper(ch)]){
                cnt++;
            }
        }
        return cnt;
    }
};