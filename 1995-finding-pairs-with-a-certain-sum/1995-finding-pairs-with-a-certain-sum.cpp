class FindSumPairs {
public:
    map<int , int> mpp;
    vector<int> v1 , v2;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        v1 = nums1;
        v2 = nums2;

        sort(v1.begin() , v1.end());

        for(int i=0; i<v2.size(); i++){
            mpp[v2[i]]++;
        }
    }
    
    void add(int index, int val) {
        int ans = v2[index];
        mpp[ans]--;
        v2[index] += val;
        mpp[v2[index]]++;
    }
    
    int count(int tot) {
        int cnt = 0;

        for(int i=0; i<v1.size(); i++){
            if(mpp.find(tot - v1[i]) != mpp.end()){
                cnt += mpp[tot - v1[i]];
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