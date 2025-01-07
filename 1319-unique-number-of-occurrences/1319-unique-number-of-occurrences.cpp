class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();

        map<int , int> mpp;
        set<int> st;

        for(int i=0; i<n; i++) mpp[arr[i]]++;

        for(auto it : mpp){
            if(st.find(it.second) != st.end()){
                return false;
            }

            st.insert(it.second);
        }
        return true;
    }
};