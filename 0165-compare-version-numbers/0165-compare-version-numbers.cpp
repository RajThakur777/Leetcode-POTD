class Solution {
public:
    int compareVersion(string version1, string version2) {
        int m = version1.size();
        int n = version2.size();

        int i = 0;
        int j = 0;

        string temp1 = "";
        string temp2 = "";

        while(i < m || j < n) {
            while(i < m && version1[i] != '.') {
                temp1 += version1[i];
                i++;
            }

            while(j < n && version2[j] != '.') {
                temp2 += version2[j];
                j++;
            }

            int num1 = stoi(temp1);
            int num2 = stoi(temp2);

            if(num1 > num2) {
                return 1;
            }
            else if(num1 < num2) {
                return -1;
            }

            if(i < version1.size()) {
                temp1 = "";
                i++;
            }
            else {
                temp1 = "0";
            }

            if(j < version2.size()) {
                temp2 = "";
                j++;
            }
            else {
                temp2 = "0";
            }
        }
        return 0;
    }
};