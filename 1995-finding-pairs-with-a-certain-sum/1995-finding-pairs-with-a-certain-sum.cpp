class FindSumPairs {
public:
    vector<int> arr1 , arr2;
    unordered_map<int , int> mpp;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        arr1 = nums1;
        arr2 = nums2;

        for(int i=0; i<arr2.size(); i++) {
            mpp[arr2[i]]++;
        }
    }
    
    void add(int index, int val) { 
        int v = arr2[index];
        mpp[v]--;
        arr2[index] += val;
        mpp[arr2[index]]++;
    }
    
    int count(int tot) {
        int cnt = 0;

        for(int i=0; i<arr1.size(); i++) {
            int val = tot - arr1[i];

            if(mpp.find(val) != mpp.end()) {
                cnt += mpp[val];
            }
        }
        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */