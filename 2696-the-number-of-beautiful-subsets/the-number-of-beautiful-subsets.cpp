class Solution {
public:
    #define ll long long

    bool isPossible(vector<ll> &arr , ll k){
        for(int i=0; i<arr.size(); i++){
            for(int j=i+1; j<arr.size(); j++){
                if(abs(arr[i] - arr[j]) == k){
                    return false;
                }
            }
        }
        return true;
    }

    void helper(int idx , vector<int>& nums , int &cnt , vector<ll> &temp , int k){
        if(idx == nums.size()){
            if(isPossible(temp , k)){
                cnt++;
            }
            return;
        }

        //pick
        temp.push_back(nums[idx]);
        helper(idx+1 , nums , cnt , temp , k);
        temp.pop_back();

        //not-pick
        helper(idx+1 , nums , cnt , temp , k);
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        int n = nums.size();

        vector<ll> temp;

        int cnt = 0;

        helper(0 , nums , cnt , temp , k);

        return cnt-1;
    }
};