class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        int cnt = 0;

        vector<int> left(n) , right(n);

        for(int i=0; i<n; i++){
            left[i] = 1;
        }

        for(int i=1; i<n; i++){
            if(ratings[i] > ratings[i-1]){
                left[i] = max(left[i] , left[i-1] + 1);
            }
        }

        for(int i=0; i<n; i++){
            right[i] = 1;
        }

        
        for(int i=n-2; i>=0; i--){
            if(ratings[i] > ratings[i+1]){
                right[i] = max(right[i] , right[i+1] + 1);
            }
        }

        for(int i=0; i<n; i++){
            cnt += max(left[i] , right[i]);
        }   
        return cnt;
    }
};