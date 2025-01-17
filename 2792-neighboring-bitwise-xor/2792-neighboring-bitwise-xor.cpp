// class Solution {
// public:
//     bool doesValidArrayExist(vector<int>& derived) {   
//         int n = derived.size();
        
//         int ones = 0;

//         for(int i=0; i<n; i++){
//             if(derived[i] == 1){
//                 ones++;
//             }
//         }

//         if(ones % 2 == 0){
//             return true;
//         }
//         return false;
//     }
// };





// class Solution {
// public:
//     bool doesValidArrayExist(vector<int>& derived) {   
//         int n = derived.size();
        
//         int xr = 0;

//         for(int i=0; i<n; i++){
//             xr ^= derived[i];
//         }

//         if(xr == 0){
//             return true;
//         }
//         return false;
//     }
// };






class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {   
        int n = derived.size();
        
        int sum = 0;

        for(int i=0; i<n; i++) sum += derived[i];

        if(sum % 2 == 0) return true;

        return false;
    }
};