class Solution {
public:

    bool isAlphaSmall(char ch) {
        return (ch >= 'a' && ch <= 'z');
    }

    bool isAlphaCapital(char ch) {
        return (ch >= 'A' && ch <= 'Z');
    }

    bool isDigit(char ch) {
        return (ch >= '0' && ch <= '9');
    }

    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
    }

    bool isConsonent(char ch) {
        return (isAlphaSmall(ch) || isAlphaCapital(ch)) && !isVowel(ch);
    }

    bool isValid(string word) {
        int n = word.size();

        if(n < 3) return false;

        int vowel = 0;
        int consonent = 0;
        for(int i=0; i<n; i++) {
            if(isVowel(word[i])) {
                vowel++;
            }
            else if((isConsonent(word[i]))){
                consonent++;
            }
        }

        if(vowel < 1 || consonent < 1) {
            return false;
        }

        for(int i=0; i<n; i++) {
            if((!isAlphaSmall(word[i])) && !(isAlphaCapital(word[i])) && !(isDigit(word[i]))){
                return false;
            }
        }
        return true;
    }
};