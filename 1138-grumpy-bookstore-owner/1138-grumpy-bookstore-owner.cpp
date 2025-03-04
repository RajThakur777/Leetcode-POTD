class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {   
        int n = grumpy.size();

        int ans = INT_MIN;
        int sum = 0;

        int val = 0;
         for(int j = 0; j < n; j++) {
            if(grumpy[j] == 0) {
                val += customers[j];
            }
        }

        int i = 0;
        for(int j=0; j<n; j++){
            if(grumpy[j] == 1){
                sum += customers[j];
            }

            while((j - i + 1) > minutes){
                if(grumpy[i] == 1){
                    sum -= customers[i];
                }
                i++;
            }

            if((j - i + 1) == minutes){
                ans = max(ans , sum);
            }
        }

        return val + ans;
    }
};