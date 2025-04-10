class Solution {
public:
    int bestClosingTime(string customers) { 
        int n = customers.size();

        vector<int> prefix(n+1);
        prefix[0] = (customers[0] == 'N' ? 1 : 0);

        for(int i=1; i<=n; i++){
            if(customers[i] == 'N'){
                prefix[i] += prefix[i-1] + 1;
            }
            else {
                prefix[i] += prefix[i-1];
            }
        }  

        vector<int> suffix(n+1);
        suffix[n] = 0;
        suffix[n-1] = (customers[n-1] == 'Y' ? 1 : 0);

        for(int i=n-2; i>=0; i--){
            if(customers[i] == 'Y'){
                suffix[i] += suffix[i+1] + 1;
            }
            else {
                suffix[i] += suffix[i+1];
            }
        }  


        int ans = INT_MAX;
        int idx = 0;
        int val = 0;

        for(int i=0; i<=n; i++){
            if(i == 0){
                val = suffix[i];
            }
            else if(i == n){
                val = prefix[i-1];
            }
            else {
                val = suffix[i] + prefix[i-1];
            }

            ans = min(ans , val);
        }

        int res = 0;
        for(int i=0; i<=n; i++) {
            if(i == 0){
                res = suffix[i];
            }
            else if(i == n){
                res = prefix[i-1];
            }
            else {
                res = suffix[i] + prefix[i-1];
            }

            if(ans == res){
                idx = i;
                break;
            }
        }
        return idx;
    }
};