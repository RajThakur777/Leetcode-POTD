class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();

        set<int> st;
        int ans = 0;

        for(int i=n-1; i>=0; i--){
            if(st.find(nums[i]) != st.end()){
                ans = i;
                break;
            }
            else {
                st.insert(nums[i]);
            }
        }
        if(st.size() == n) return 0;
        
        return (ans + 1) % 3 == 0 ? (ans + 1) / 3 : ((ans + 1) / 3) + 1;
    }
};