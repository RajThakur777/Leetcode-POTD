class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int n = nums.size();

        stack<int> st;

        for(int i=0; i<n; i++) {
            int num = nums[i];

            while(!st.empty()) {
                int GCD = __gcd(num , st.top());

                if(GCD > 1) {
                    num = int((1LL * num * st.top()) / GCD);
                    st.pop();
                }
                else {
                    break;
                }
            }
            st.push(num);
        }

        vector<int> ans;

        while(!st.empty()) {
            int num = st.top();
            st.pop();
            ans.push_back(num);
        }

        reverse(ans.begin() , ans.end());

        return ans;
    }
};