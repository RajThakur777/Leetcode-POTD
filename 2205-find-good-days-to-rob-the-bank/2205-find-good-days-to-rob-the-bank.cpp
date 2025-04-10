class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& arr, int t) {
        int n = arr.size();

        vector<int> dec(n , 0) , inc(n , 0) , ans;

        for(int i=1; i<n; i++) if(arr[i] <= arr[i-1]) dec[i] += dec[i-1] + 1;

        for(int i=n-2; i>=0; i--) if(arr[i] <= arr[i+1]) inc[i] += inc[i+1] + 1;

        for(int i=0; i<n; i++)
           if(dec[i] >= t && inc[i] >= t) ans.push_back(i);
           
        return ans;   
    }
};