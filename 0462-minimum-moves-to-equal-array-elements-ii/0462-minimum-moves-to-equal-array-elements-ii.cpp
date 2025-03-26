class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();

        vector<int> temp = nums;

        sort(temp.begin() , temp.end());

        int mid = temp[(n / 2)];

        int ans1 = 0;
        for(int i=0; i<n; i++){
            if(temp[i] < mid){
                ans1 += (mid - temp[i]);
            }
            else {
                ans1 += (temp[i] - mid);
            }
        }
        return ans1;
    }
};