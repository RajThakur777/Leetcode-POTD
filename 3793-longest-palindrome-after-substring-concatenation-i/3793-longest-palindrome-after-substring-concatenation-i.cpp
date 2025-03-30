class Solution {
public:

    bool isPalindrome(string str){
        for(int i=0; i<str.size()/2; i++){
            if(str[i] != str[str.size()-i-1]) return false;
        }
        return true;
    }

    int longestPalindrome(string s, string t) {
        int m = s.size();
        int n = t.size();

        int ans = INT_MIN;

        for(int i=0; i<=m; i++){
            for(int j=i; j<=m; j++){
                string str1 = s.substr(i , j-i);

                for(int k=0; k<=n; k++){
                    for(int l=k; l<=n; l++){
                        string str2 = t.substr(k , l-k);

                        string comb = str1 + str2;

                        if(isPalindrome(comb)){
                            ans = max(ans , (int)comb.size());
                        }
                    }
                }
            }
        }
        return ans;
    }
};