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
    int getDecimalValue(ListNode* head) {
        if(head == nullptr) return 0;

        int len = 0;
        ListNode* temp = head;

        while(temp != nullptr) {
            temp = temp->next;
            len++;
        }

        len--;

        int num = 0;
        temp = head;
        while(temp != nullptr) {
            int data = temp->val;
            num += ((data) * ((int)(pow(2 , len))));
            len--;
            temp = temp->next;
        }
        return num;
    }
};