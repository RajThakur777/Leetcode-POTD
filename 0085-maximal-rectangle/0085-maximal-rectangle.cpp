class Solution {
public:

    int helper(vector<int> &v){
        //nsl
        stack<int> s1;
        int n = v.size();
        vector<int> nsl(n);
        for(int i=0; i<n; i++){
            while(!s1.empty() && v[i] <= v[s1.top()]){
                s1.pop();
            }
            if(s1.empty()){
                nsl[i] = -1;
            }
            else {
                nsl[i] = s1.top();
            }
            s1.push(i);
        }
        //nsr
        vector<int> nsr(n);
        stack<int> s2;
         for(int i=n-1; i>=0; i--){
            while(!s2.empty() && v[i] <= v[s2.top()]){
                s2.pop();
            }
            if(s2.empty()){
                nsr[i] = n;
            }
            else {
                nsr[i] = s2.top();
            }
            s2.push(i);
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            int ht = v[i];
            int wt = nsr[i] - nsl[i] - 1;
            ans = max(ans , ht*wt);
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> v(n , vector<int>(m , 0));

        for(int i=0; i<m; i++){
            v[0][i] = matrix[0][i] - '0';
        }

        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == '0'){
                    v[i][j] = 0;
                }
                else {
                    v[i][j] = 1 + v[i-1][j];
                }
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            ans = max(ans , helper(v[i]));
        }
        return ans;
    }
};