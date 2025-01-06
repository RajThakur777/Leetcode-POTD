class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();

        vector<int> res(n);

        for(int i=0; i<n; i++){
            int cnt = 0;
            for(int j=0; j<i; j++){
                if(boxes[j] == '1'){
                    cnt += (i - j);
                }
            }

            for(int k=i+1; k<n; k++){
                if(boxes[k] == '1'){
                    cnt += (k - i);
                }
            }

            res[i] = cnt;
        }
        return res;
    }
};