class Solution {
public:
    int minOperations(int n) { 
        vector<int> v(n);

        for(int i=0; i<n; i++){
            v[i] = (2 * i) + 1;
        } 

        if(n % 2  != 0){
            int val = v[n / 2];
            int cnt = 0;

            for(int i=0; i<n/2; i++){
                cnt += (v[n/2] - v[i]);
            }

            return (cnt);
        }
        else {
            int val = v[n / 2];
            int cnt = 0;

            for(int i=0; i<n/2; i++){
                cnt += (v[n/2] - v[i]);
            }

            for(int i=n/2; i<n; i++){
                cnt += (v[i] - v[n/2]);
            }
            return cnt / 2;
        }
    }
};