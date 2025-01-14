//Brute force:
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) { 
        int n = A.size();

        vector<int> c;

        for(int i=0; i<n; i++){
            int cnt = 0;
            for(int j=0; j<=i; j++){
                set<int> st;
                st.insert(A[j]);

                for(int k=0; k<=i; k++){
                    if(st.find(B[k]) != st.end()){
                        cnt++;
                    }
                }
            }
            c.push_back(cnt);
        }
        return c;
    }
};