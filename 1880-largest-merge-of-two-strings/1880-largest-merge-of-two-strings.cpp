class Solution {
public:
    string largestMerge(string w1, string w2) {
        string me;
        int n1 = w1.size();
        int n2 = w2.size();
        int i = 0, j = 0;
        while (i < n1 && j < n2) {
            if (w1[i] < w2[j]) {
                me += w2[j];
                j++;
            } else if (w1[i] > w2[j]) {
                me += w1[i];
                i++;
            } else {
                string t1 = w1.substr(i);
                string t2 = w2.substr(j);
                if (t1 > t2) {
                    me += w1[i];
                    i++;
                } else {
                    me += w2[j];
                    j++;
                }
            }
        }
        while (i < n1) {
            me += w1[i];
            i++;
        }
        while (j < n2) {
            me += w2[j];
            j++;
        }
        return me;
    }
};