class Solution {
public:

    bool isPossible(int mid , vector<int>& quantities , int n){
        int cnt = 0;

        for(int i=0; i<quantities.size(); i++){
            cnt += ceil((double)quantities[i] / mid);
        }
        return cnt <= n;
    }

    int minimizedMaximum(int n, vector<int>& quantities) { 
        int val = quantities.size();

        int low = 1;
        int high = *max_element(quantities.begin() , quantities.end());

        int ans = 0;
        while(low <= high) {
            int mid = (low + high) / 2;

            if(isPossible(mid , quantities , n)){
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }   
        return ans;
    }
};