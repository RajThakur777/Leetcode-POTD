class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans;

        set<int> st;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k<n; k++){

                    if(i == j || j == k || i == k) continue;
                    
                    if(nums[k] % 2 == 1) continue;

                    if(nums[i] == 0) continue;

                    int num = nums[i] * 100 + nums[j] * 10 + nums[k];

                    st.insert(num);
                }
            }
        }
        for(auto it : st){
            ans.push_back(it);
        }
        sort(ans.begin() , ans.end());

        return ans;
    }
};