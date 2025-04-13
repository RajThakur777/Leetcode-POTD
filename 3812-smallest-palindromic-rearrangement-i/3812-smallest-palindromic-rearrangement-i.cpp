class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();

        map<char , int> mpp;
        for(int i=0; i<n; i++){
            mpp[s[i]]++;
        }

        string ans = "";

        char ch;

        bool flag = false;
        for(auto it : mpp){
            if(it.second % 2 != 0){
                flag = true;
                ch = it.first;
            }
        }
        
        for(auto it : mpp){
            ans.append((it.second) / 2 , it.first);
        }

        string temp = ans;
        reverse(temp.begin() , temp.end());

        if(flag){
            ans += ch; 
        }

        ans += temp;

        return ans;
    }
};