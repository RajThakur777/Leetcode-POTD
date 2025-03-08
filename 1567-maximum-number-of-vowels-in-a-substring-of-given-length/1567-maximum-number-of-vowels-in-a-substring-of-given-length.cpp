class Solution {
public:

    bool isVowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;

        return false;
    }

    int maxVowels(string s, int k) {
        int n = s.size();

        int ans = INT_MIN;
        int vowel = 0;

        int i = 0;
        for(int j=0; j<n; j++){
            if(isVowel(s[j])){
                vowel++;
            }

            while((j - i + 1) > k){
                if(isVowel(s[i])){
                    vowel--;
                }
                i++;
            }

            if((j - i + 1) == k){
                ans = max(ans , vowel);
            }
        }  
        return ans;
    }
};