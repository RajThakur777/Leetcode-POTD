class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> res(n , 0);

        int i = 0;
        int j = 0;

        int k = 0;

        while(i < n && j < n){
            while(i < n && nums[i] < 0){
                i++;
            }
            res[k++] = nums[i++];

            while(j < n && nums[j] > 0){
                j++;
            }
            res[k++] = nums[j++];
        }
        return res;
    }
};