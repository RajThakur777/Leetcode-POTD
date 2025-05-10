class Solution {
public:

    bool isVowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            return true;
        }
        return false;
    }
    
    int maxFreqSum(string s) {
        int n = s.size();

        map<char , int> mpp1;
        for(int i=0; i<n; i++){
            if(isVowel(s[i])){
                mpp1[s[i]]++;
            }
        }

         map<char , int> mpp2;
        for(int i=0; i<n; i++){
            if(!isVowel(s[i])){
                mpp2[s[i]]++;
            }
        }
        int maxi1 = 0;
        int maxi2 = 0;

        for(auto it : mpp1){
            maxi1 = max(maxi1 , it.second);
        }

        for(auto it : mpp2){
            maxi2 = max(maxi2 , it.second);
        }
        return maxi1 + maxi2;
    }
};