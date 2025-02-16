class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int n = s.size();
        
        for (int i = 0; i <= n - k; i++) {
            string temp = s.substr(i, k); 
            
            map<char , int> mpp;
            for(int j=0; j<temp.size(); j++){
                mpp[temp[j] - 'a']++;
            }

            if(mpp.size() == 1){
                char ch1 = (i > 0) ? s[i - 1] : ' ';
                
                char ch2 = (i + k < n) ? s[i + k] : ' ';
                
                if (ch1 != temp[0] && ch2 != temp[0]) {
                    return true; 
                }
            }
        }
        return false;  
    }
};



