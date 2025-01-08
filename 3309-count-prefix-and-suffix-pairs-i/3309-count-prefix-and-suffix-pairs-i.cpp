//Brute force:
class Solution {
public:

    bool isSuffix(string str1 , string str2){
        int i = str1.size() - 1;
        int j = str2.size() - 1;
        int n = str1.size();

        while(i >= 0){
            if(str1[i] != str2[j]){
                return false;
            }
            else {
                i--;
                j--;
            }
        }
        return true;
    }


    bool isPrefix(string str1 , string str2){
        int i = 0;
        int j = 0;
        int n = str1.size();

        while(i < n){
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

    bool isPrefixAndSuffix(string str1 , string str2){
        if(isPrefix(str1 , str2) && isSuffix(str1 , str2)){
            return true;
        }
        return false;
    }

    int countPrefixSuffixPairs(vector<string>& words) {   
        int n = words.size();

        int cnt = 0;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(isPrefixAndSuffix(words[i] , words[j])){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};