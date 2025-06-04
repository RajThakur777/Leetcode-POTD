class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.size();

        if (numFriends == 1) {
            return word;
        }

        string ans;

        for (int i = 0; i < word.size(); i++) {
            ans = max(ans , word.substr(i , min(n -  numFriends + 1 , n - i)));
        }        
        return ans;
    }
};