class Solution {
public:
    string customSortString(string order, string s) {
        int n = order.size(); 

        map<int , int> mpp;
        for(int i=0; i<s.size(); i++){
            mpp[s[i]]++;
        }

        string ans = "";
        for(int i=0; i<order.size(); i++){
            if(mpp.find(order[i]) != mpp.end()){
                int freq = mpp[order[i]];
                ans.append(freq , order[i]);
                mpp.erase(order[i]);
            }
        }

        for(auto it : mpp){
            char ch = it.first;
            int freq = it.second;

            ans.append(freq , ch);
        }
        return ans;
    }
};