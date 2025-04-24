//Brute force:
// class Solution {
// public:
//     int countCompleteSubarrays(vector<int>& nums) {
//         int n = nums.size();

//         set<int> st;
//         for(int i=0; i<n; i++){
//             st.insert(nums[i]);
//         }

//         int distinct = st.size();

//         if(distinct == 1) {
//             return (n * (n + 1)) / 2;
//         }

//         int cnt = 0;

//         for(int i=0; i<n; i++){
//             map<int , int> mpp;
//             for(int j=i; j<n; j++) {
//                 mpp[nums[j]]++;

//                 if(mpp.size() == distinct){
//                     cnt++;
//                 }
//             }
//         }
//         return cnt;
//     }
// };




//Sliding Window + Hashing:
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();

        set<int> st;
        for(int i=0; i<n; i++){
            st.insert(nums[i]);
        }

        int distinct = st.size();

        if(distinct == 1) {
            return (n * (n + 1)) / 2;
        }

        int cnt = 0;

        map<int , int> mpp;

        int i = 0;
        for(int j=0; j<n; j++){
            mpp[nums[j]]++;

            while(mpp.size() == distinct){
                cnt += (n - j);

                mpp[nums[i]]--;

                if(mpp[nums[i]] == 0){
                    mpp.erase(nums[i]);
                }
                i++;
            }
        }
        return cnt;
    }
};
