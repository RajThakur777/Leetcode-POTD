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
                    
                    int a = nums[i];
                    int b = nums[j];
                    int c = nums[k];

                    if(a == 0){
                        break;
                    }
                    else if(a == 0 && b == 0 && c == 0){
                        break;
                    }
                    else {
                        int num = a * 100 + b * 10 + c;

                        if(num % 2 == 0){
                            st.insert(num);
                        }
                    }
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