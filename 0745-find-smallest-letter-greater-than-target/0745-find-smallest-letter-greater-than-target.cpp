class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();

        char ch = letters[0];

        int low = 0;
        int high = n-1;

        while(low <= high){
            int mid = (low + high) / 2;

            if(letters[mid] > target){
                ch = letters[mid];
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ch;
    }
};