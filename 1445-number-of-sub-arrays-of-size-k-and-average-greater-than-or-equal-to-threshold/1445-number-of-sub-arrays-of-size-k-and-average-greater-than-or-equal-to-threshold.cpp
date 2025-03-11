class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();

        int cnt = 0;

        int sum = 0;
        int i = 0;

        for(int j=0; j<n; j++){
            sum += arr[j];

            while((j - i + 1) > k){
                sum -= arr[i];
                i++;
            }

            if((j - i + 1) == k){
                if((sum) / k >= threshold){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};