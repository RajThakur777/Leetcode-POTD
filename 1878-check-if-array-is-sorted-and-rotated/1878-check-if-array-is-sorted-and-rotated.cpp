class Solution {
public:
    bool check(vector<int>& nums) {  
        int n = nums.size();

        bool flag = false;
        vector<int> copy = nums;
        sort(copy.begin() , copy.end());

        for(int pos=1; pos<=n; pos++){
            vector<int> res(n);
            for(int i=0; i<n; i++){
                res[i] = (copy[(i+pos) % n]);
            }

            if(res == nums){
                flag = true;
                break;
            }
        } 
        if(flag){
            return true;
        }
        return false;
    }
};