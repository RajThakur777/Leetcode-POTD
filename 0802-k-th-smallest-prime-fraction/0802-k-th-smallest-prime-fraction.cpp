//Brute force:
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<float> v;

        int n = arr.size();

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                v.push_back(((float)arr[i] / (float)arr[j]));
            }
        }

        sort(v.begin() , v.end());

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(v[k-1] == (((float)arr[i] / (float)arr[j]))){
                    return {arr[i] , arr[j]};
                }
            }
        }
        return {0 , 1};
    }
};