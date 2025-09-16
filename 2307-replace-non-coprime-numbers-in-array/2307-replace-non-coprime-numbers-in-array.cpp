class Solution {
public:
    int GCD(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> st;

        for(int num: nums) {
            int val = num;
            while(!st.empty()) {
                int gcd = GCD(st.top(), val);

                if(gcd > 1) {
                    val = int((1LL * val * st.top()) / gcd);
                    st.pop();
                } else break;
            }
            st.push(val);
        }

        vector<int> ans(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};