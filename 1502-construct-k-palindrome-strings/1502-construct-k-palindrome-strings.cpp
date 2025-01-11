class Solution {
public:
    bool canConstruct(string s, int k) {  
        int n = s.size();

        map<char , int> mpp;
        for(int i=0; i<n; i++){
            mpp[s[i]]++;
        }

        if(s.size() < k){
            return false;
        }        
        else {
            int cnt = 0;
            int cnt2 = 0;
            for(auto it : mpp){
                if(it.second == 1){
                    cnt++;
                }
                else if(it.second % 2 != 0){
                    cnt2++;
                }
            }

            if(cnt > k){
                return false;
            }
            else if(cnt2 > k){
                return false;
            }
            return true;
        }
    }
};