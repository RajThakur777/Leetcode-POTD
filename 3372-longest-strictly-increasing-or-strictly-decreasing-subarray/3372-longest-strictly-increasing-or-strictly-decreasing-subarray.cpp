class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) { 
        int n = nums.size();

        //increasing 
        int maxi1 = 1;
        for(int i=0; i<n; i++){
            int len1 = 1;
            for(int j=i+1; j<n; j++){
                if(nums[j] > nums[j-1]){
                    len1++;
                    maxi1 = max(maxi1 , len1);
                }
                else {
                    break;
                }
            }
        }

        //decreasing 
        int maxi2 = 1;
        for(int i=0; i<n; i++){
            int len2 = 1;
            for(int j=i+1; j<n; j++){
                if(nums[j] < nums[j-1]){
                    len2++;
                    maxi2 = max(maxi2 , len2);
                }
                else {
                    break;
                }
            }
        }
        return max(maxi1 , maxi2);
    }
};