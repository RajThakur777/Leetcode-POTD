class Solution {
public:
    int maxDifference(string s) {
        int n = s.size();

        map<char , int> mpp;
        for(int i=0; i<n; i++){
            mpp[s[i]]++;
        }

        int maxi_odd = INT_MIN;
        int mini_even = INT_MAX;

        for(auto it : mpp){
            if(it.second % 2 == 0 && it.second < mini_even){
                mini_even = it.second;
            }
        }

        for(auto it : mpp){
            if(it.second % 2 != 0 && it.second > maxi_odd){
                maxi_odd = it.second;
            }
        }
        return maxi_odd - mini_even;
    }
};