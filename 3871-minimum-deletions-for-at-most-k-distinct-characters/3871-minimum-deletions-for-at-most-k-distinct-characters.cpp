class Solution {
public:
    int minDeletion(string s, int k) {
        int n = s.size();

        map<char , int> mpp;
        for(int i=0; i<n; i++){
            mpp[s[i]]++;
        }

        if(mpp.size() <= k) return 0;
        
        vector<int> res;
        for(auto it : mpp){
            res.push_back(it.second);
        }
        
        sort(res.begin() , res.end());

        int cnt = mpp.size() - k;
        int val = 0;
        int ans = 0;
        for(int i=0; i<res.size(); i++){
            if(val != cnt){
                ans += res[i];
                val++;
            }
            else {
                break;
            }
        }
        return ans;
    }
};