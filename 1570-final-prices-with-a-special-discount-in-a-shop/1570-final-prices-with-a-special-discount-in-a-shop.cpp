class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {  
        int n = prices.size();

        vector<int> nsr(n);
        stack<int> st;

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && st.top() > prices[i]){
                st.pop();
            }
            if(st.empty()){
                nsr[i] = 0;
            }
            else {
                nsr[i] = st.top();
            }
            st.push(prices[i]);
        }    

        vector<int> ans(n);
        for(int i=0; i<n; i++){
            ans[i] = prices[i] - nsr[i];
        }
        return ans;
    }
};