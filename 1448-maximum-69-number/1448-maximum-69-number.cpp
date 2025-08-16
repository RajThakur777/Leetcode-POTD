class Solution {
public:
    int maximum69Number (int num) {
        string res = to_string(num);

        for(int i=0; i<res.size(); i++) {
            if(res[i] == '6') {
                res[i] = '9';
                break;
            }
        } 
        return stoi(res);
    }
};