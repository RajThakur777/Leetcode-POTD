// //Brute force:
// class Solution {
// public:
//     int maxArea(vector<int>& height) {    
//         int ans = 0;

//         for(int i=0; i<height.size(); i++){
//             for(int j=i+1; j<height.size(); j++){
//                 ans = max(ans , ((min(height[i] , height[j]))) * (j - i));
//             }
//         }
//         return ans;
//     }
// };





class Solution {
public:
    int maxArea(vector<int>& height) {    
        int ans = INT_MIN;

        int n = height.size();

        int i = 0;
        int j = n-1;

        while(i < j){
            if(height[i] <= height[j]){
                ans = max(ans , (j - i) * (height[i]));
                i++;
            }
            else {
                ans = max(ans , (j - i) * (height[j]));
                j--;
            }
        }
        return ans;
    }
};