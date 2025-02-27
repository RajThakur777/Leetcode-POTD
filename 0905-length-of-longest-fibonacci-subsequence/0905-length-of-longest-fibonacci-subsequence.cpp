//Brute force:
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) { 
        int n = arr.size();

        unordered_set<int> st(arr.begin(), arr.end());

        int ans = 0;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int prev = arr[j];
                int curr = arr[i] + arr[j];
                int len = 2;

                while(st.find(curr) != st.end()){
                    int val = curr;
                    curr += prev;
                    prev = val;

                    ans = max(ans , ++len);
                }
            }
        }
        return ans;
    }
};