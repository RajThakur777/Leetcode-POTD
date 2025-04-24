class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();

        set<string> st;

        int i = 0;
        for(int j=0; j<n; j++){
            while((j - i + 1) > k){
                i++;
            }

            if((j - i + 1) == k){
                string res = s.substr(i , k);

                st.insert(res);
            }
        }
        return (st.size() == pow(2 , k));
    }
};