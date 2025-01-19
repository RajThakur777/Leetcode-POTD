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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) return head;
        
        ListNode* temp = head;
        int len = 0;

        while(temp != nullptr){
            temp = temp->next;
            len++;
        }

        k = k % len;
        
        while(k > 0){
            ListNode* prev = nullptr;
            ListNode* dummy = head;
            while(dummy->next->next != nullptr){
                dummy = dummy->next;
            }

            ListNode* value = new ListNode(dummy->next->val);
            prev = value;
            prev->next = head;
            head = prev;
            dummy->next = nullptr;
            dummy = head;
            k--;
        }
        return head;
    }
};