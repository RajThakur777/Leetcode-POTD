class Solution {
public:
    vector<int> sortByReflection(vector<int>& nums) {
        int n = nums.size();

        map<int , vector<int>> mpp;

        for(int i=0; i<n; i++) {
            int num = nums[i];

            int bits = log2(num);

            string str;
            for(int j=0; j<=bits; j++) {
                if((num & (1 << j)) > 0) {
                    str += '1';
                }
                else {
                    str += '0';
                }
            }

            string res = str;

            int reverseNumber = 0;
            int idx = 0;
            for(int i=res.size()-1; i>=0; i--) {
                if(res[i] == '1') {
                    reverseNumber += (1 * pow(2 , idx));
                }
                else {
                    reverseNumber += (0 * pow(2 , idx));
                }
                idx++;
            }

            mpp[reverseNumber].push_back(num);
        }

        vector<int> ans;

        for(auto it : mpp) {
            int rev = it.first;
            vector<int> arr = it.second;

            sort(arr.begin() , arr.end());

            for(auto x : arr) {
                ans.push_back(x);
            }
        }
        return ans;
    }
};