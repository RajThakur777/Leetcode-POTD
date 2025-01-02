class Solution {
public:
    bool vowel(char ch){
        if(ch == 'a' || ch == 'e' || ch =='i' || ch == 'o' || ch =='u'){
            return true;
        }
        return false;
    }

    bool isVowel(string s){
        int n = s.size();

        if((vowel(s[0])) && vowel(s[n-1])){
            return true;
        }
        return false;
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> ans;
        int n = words.size();

        vector<int> res(n , 0);

        for(int i=0; i<n; i++){
            if(isVowel(words[i])){
                res[i] = 1;
            }
        }

        int prefix[n+1];
        prefix[0] = res[0];
        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1] + res[i];
        }

        for(int i=0; i<queries.size(); i++){
            int l = queries[i][0];
            int r = queries[i][1];

            if(l == 0){
                ans.push_back(prefix[r]);
            }
            else {
                ans.push_back(prefix[r] - prefix[l-1]);
            }
        }
        return ans;
    }
};