/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    bool isPalindrome(vector<int> res) {
        int i = 0;
        int j = res.size() - 1;

        while(i <= j) {
            if(res[i] != res[j]) {
                return false;
            }
            else {
                i++;
                j--;
            }
        }
        return true;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;

        vector<int> res;

        while(temp != nullptr) {
            res.push_back(temp->val);
            temp = temp->next;
        }
        return isPalindrome(res);
    }
};