class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();

        int cnt = 0;

        set<int> st;
        for(int i=0; i<n; i++){
            st.insert(arr[i]);
        }

        int res = 0;

        for(int i=1; i<=10000; i++){
            if(st.find(i) == st.end()){
                cnt++;

                if(cnt == k){
                    res = i;
                    break;
                }
            }
        }
        return res;
    }
};