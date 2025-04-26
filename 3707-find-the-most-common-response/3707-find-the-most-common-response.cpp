class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        int n = responses.size();

        map<string , int> mpp;
        
        for(int i=0; i<n; i++){
            vector<string> v1 = responses[i];

            set<string> st;
            for(int j=0; j<v1.size(); j++){
                st.insert(v1[j]);
            }

            for(auto it : st){
                mpp[it]++;
            }
        }
        int maxi = INT_MIN;
        for(auto it : mpp){
            if(it.second > maxi) {
                maxi = it.second;
            }
        }

        string ans;
        for(auto it : mpp){
            if(it.second == maxi){
                ans = it.first;
                break;
            }
        }
        return ans;
    }
};