//Sliding Window:
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) { 
        int n = customers.size();

        //calculate initial number of customers which are satisfied:
        int sum = 0;
        for(int i=0; i<n; i++){
            if(grumpy[i] == 0){
                sum += customers[i];
            }
        }  

        //check every window of size minute having not satisfied customers and take maximum:
        int i = 0;
        int val = 0;
        int ans = INT_MIN;

        for(int j=0; j<n; j++){
            if(grumpy[j] == 1){
                val += customers[j];
            }

            while((j - i + 1) > minutes){
                if(grumpy[i] == 1){
                    val -= customers[i];
                }
                i++;
            }

            if((j - i + 1) == minutes){
                ans = max(ans , val);
            }
        }
        return ans + sum;
    }
};