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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr) return head;

        ListNode* temp = head;
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        int cnt = 1;

        while(temp != nullptr) {
            if(cnt % 2 == 0) {
                temp = temp->next;
                cnt++;
            }
            else {
                curr->next = new ListNode(temp->val);
                temp = temp->next;
                curr = curr->next;
                cnt++;
            }
        }

        cnt = 2;
        temp = head->next;

        while(temp != nullptr) {
            if(cnt % 2 == 0) {
                curr->next = new ListNode(temp->val);
                temp = temp->next;
                curr = curr->next;
                cnt++;
            }
            else {
                temp = temp->next;
                cnt++;
            }
        }
        return dummy->next;
    }
};